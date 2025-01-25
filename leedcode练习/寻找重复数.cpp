/*
  Ѱ���ظ���
  ����һ������n+1������������nums��
  �����ֶ���[1��n]��Χ�� (����1��n)����֪���ٴ���һ���ظ���������
  ����numsֻ��һ���ظ�����������������ظ�����
  ����ƵĽ���������벻�޸�����numsֻ�ó�����0(1)�Ķ���ռ�
*/
#include <stdio.h>
int findDuplicate(int *nums, int numsSize) {
    int slow = 0, fast = 0;

    // ʹ�ÿ���ָ���ҵ�������
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // ������ָ�룬���ҵ��������
    slow = 0;
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow; // �����ظ�������
}
int main() {
    int nums[] = {1, 3, 4, 2, 2}; // ʾ����������
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int duplicate = findDuplicate(nums, numsSize);

    printf("�ظ���������: %d\n", duplicate);

    return 0;
}

