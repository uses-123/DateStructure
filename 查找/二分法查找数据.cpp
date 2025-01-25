#include <stdio.h>

int binary_search(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1; // 没有找到
}

int main() {
    int arr[] = {1, 3, 4, 6, 8, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 11;
    
    int index = binary_search(arr, n, target);
    if (index == -1) {
        printf("没有找到 %d\n", target);
    } else {
        printf("%d 在数组中的下标为 %d\n", target, index);
    }
    
    return 0;
}

