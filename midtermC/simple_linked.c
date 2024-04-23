#define _CRT_SECURE_NO_WARNINGS 
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "simple_linked.h"

// ���� ó�� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;					// (2)
	p->link = head;	// ��� �������� ���� ����	//(3)
	head = p;	// ��� ������ ����		//(4)
	return head;	// ����� ��� ������ ��ȯ
}

// ��� pre �ڿ� ���ο� ��� ����
ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;		//(2)
	p->link = pre->link;	//(3)	
	pre->link = p;		//(4)	
	return head;		//(5)	
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;	// (1)
	head = removed->link;	// (2)
	free(removed);		// (3)
	return head;		// (4)
}

// pre�� ����Ű�� ����� ���� ��带 �����Ѵ�. 
ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;		// (2)
	free(removed);			// (3)
	return head;			// (4)
}

void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

// ���� ���̸� ���ϴ� �Լ�
int get_length(ListNode* head) {
    int length = 0; // ����� ������ ���� ����
    for (ListNode* p = head; p != NULL; p = p->link)
        length++; // ��带 ��ȸ�ϸ� ������ ��
    return length; // ����(����) ��ȯ
}

// Ȧ�� ���� ���� ���� ���ϴ� �Լ�
int suqare_sum(ListNode* head) {
    int sum = 0; // ������ ���� �����ϴ� ����
    for (ListNode* p = head; p != NULL; p = p->link) {
        if (p->data % 2 != 0) // ���� ����� ���� Ȧ������ Ȯ��
            sum += p->data * p->data; // Ȧ���̸� ���� �� ����
    }
    return sum; 
}

// ������ ��� ��Ҹ� �������� ����ϴ� ��� �Լ�
void print_reverse(ListNode* head) {
    if (head == NULL)
        return;
    print_reverse(head->link); // ���� ����
    printf("%d ", head->data);
}

// �־��� ������ ���� ���� ��带 ���ÿ��� �����ϴ� �Լ�
ListNode* remove_list(ListNode* head, int data) {
    ListNode* now = head, * previous = NULL;
    while (now != NULL && now->data != data) {
        previous = now; // ���� ��带 previous�� ����
        now = now->link; // ���� ���� �̵�
    }
    if (now != NULL) { // ������ ��带 ã�� ���
        if (previous == NULL) // head�� �����ϴ� ���
            head = delete_first(head); // 1�� ��带 ����
        else
            head = delete(head, previous); // �־��� ��带 ����
    }
    return head; 
}

// �� ������ ��ġ�� �Լ�
ListNode* merge_list(ListNode* head1, ListNode* head2) {
    if (head1 == NULL) return head2; // 1�� ������ ��������� 2�� ���� ��ȯ
    if (head2 == NULL) return head1; // 2�� ������ ��������� 1�� ���� ��ȯ

    ListNode* mergedHead = NULL; // ���ս����� ���
    if (head1->data < head2->data) { // ���� ���� ���� ��带 ���ս����� ���� ����
        mergedHead = head1;
        mergedHead->link = merge_list(head1->link, head2); // ������ ���� ��ġ��
    }
    else {
        mergedHead = head2;
        mergedHead->link = merge_list(head1, head2->link); // ������ ���� ��ġ��
    }
    return mergedHead;
}

// ���ÿ� �Ҵ�� �޸� ����
void free_stack(ListNode* head) {
    ListNode* now = head;
    ListNode* next;

    while (now != NULL) {
        next = now->link;
        free(now);
        now = next;
    }
}
