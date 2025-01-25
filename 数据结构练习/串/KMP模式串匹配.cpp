/*
	利用KMP算法(本质是模式匹配算法)解决字符串匹配问题
	 
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include<stdlib.h>
// 判断字符串 pattern 是否为字符串 text 的子串
bool hasSubstring(char text[], char pattern[]) {
    int i = 0, j = 0, k = 0;
    while (text[i] != '\0' && pattern[j] != '\0') {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        } else {
            j = 0;
            k++;
            i = k;
        }
    }
    if (pattern[j] == '\0') {
        return true;
    }
    return false;
}
// 计算模式串 pattern 的临时数组 LPS
int* computeTemporaryArray(char pattern[]) {
    int len = strlen(pattern);
    int *lps = (int *)malloc(len * sizeof(int));
    if (lps == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    int index = 0;
    for (int i = 1; i < len;) {
        if (pattern[i] == pattern[index]) {
            lps[i] = index + 1;
            index++;
            i++;
        } else {
            if (index != 0) {
                index = lps[index - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
// 使用 KMP 算法判断字符串 pattern 是否为字符串 text 的子串
bool KMP(char text[], char pattern[]) {
    int *lps = computeTemporaryArray(pattern);
    if (lps == NULL) {
        return false;
    }
    int i = 0, j = 0;
    while (text[i] != '\0' && pattern[j] != '\0') {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    free(lps);
    if (pattern[j] == '\0') {
        return true;
    }
    return false;
}

int main() {
    char str[] = "abcxabcdabcdabcy";
    char subString[] = "abcdabcy";
    bool result = KMP(str, subString);
    if (result) {
        printf("Substring found\n");
    } else {
        printf("Substring not found\n");
    }

    return 0;
}
