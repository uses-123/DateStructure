#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head, *p, *q;  // head为链表头
    int n, i, k;

    // 输入n和k
//    printf("input n and k:");
    scanf("%d %d", &n, &k);

    // 建立链表
    head = p = (struct node *)malloc(sizeof(struct node));  // 创建第一个结点，head指向表头结点，p指向表尾结点
    p->data = 1;
    for (i = 2; i <= n; i++) {  // 构建单循环链表
        q = (struct node *)malloc(sizeof(struct node));  // q为当前正在创建的结点
        q->data = i;
        p->next = q;
        p = q;  // 将q链入表尾
    }
    p->next = head;  // 头尾相连

    // 删除过程
    q = head;  // head报数为1
    while (q->next->next != q) {  // 表中元素多于两个
        for (i = 0; i < k - 1; i++) {
            p = q;
            q = q->next;
        }

        // 删除q
        p->next = q->next;  // 绕过结点q
//        printf("%d\t", q->data);  // 显示被删除的数据
        free(q);  // 回收被删除的空间
        q = p->next;  // 让q指向报1的结点
    }

    // 打印结果
    printf("%d %d\n", q->data, q->next->data);

    // 释放链表的内存
    free(q->next);
    free(q);

    return 0;
}

