#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head, *p, *q;  // headΪ����ͷ
    int n, i, k;

    // ����n��k
//    printf("input n and k:");
    scanf("%d %d", &n, &k);

    // ��������
    head = p = (struct node *)malloc(sizeof(struct node));  // ������һ����㣬headָ���ͷ��㣬pָ���β���
    p->data = 1;
    for (i = 2; i <= n; i++) {  // ������ѭ������
        q = (struct node *)malloc(sizeof(struct node));  // qΪ��ǰ���ڴ����Ľ��
        q->data = i;
        p->next = q;
        p = q;  // ��q�����β
    }
    p->next = head;  // ͷβ����

    // ɾ������
    q = head;  // head����Ϊ1
    while (q->next->next != q) {  // ����Ԫ�ض�������
        for (i = 0; i < k - 1; i++) {
            p = q;
            q = q->next;
        }

        // ɾ��q
        p->next = q->next;  // �ƹ����q
//        printf("%d\t", q->data);  // ��ʾ��ɾ��������
        free(q);  // ���ձ�ɾ���Ŀռ�
        q = p->next;  // ��qָ��1�Ľ��
    }

    // ��ӡ���
    printf("%d %d\n", q->data, q->next->data);

    // �ͷ�������ڴ�
    free(q->next);
    free(q);

    return 0;
}

