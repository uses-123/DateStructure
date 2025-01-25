/*
  寻找重复数
  给定一个包含n+1个整数的数组nums，
  其数字都在[1，n]范围内 (包括1和n)，可知至少存在一个重复的整数。
  假设nums只有一个重复的整数，返回这个重复的数
  你设计的解决方案必须不修改数组nums只用常量级0(1)的额外空间
*/
#include <stdio.h>
int findDuplicate(int *nums, int numsSize) {
    int slow = 0, fast = 0;

    // 使用快慢指针找到相遇点
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // 重置慢指针，以找到环的入口
    slow = 0;
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow; // 返回重复的数字
}
int main() {
    int nums[] = {1, 3, 4, 2, 2}; // 示例输入数组
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int duplicate = findDuplicate(nums, numsSize);

    printf("重复的数字是: %d\n", duplicate);

    return 0;
}

