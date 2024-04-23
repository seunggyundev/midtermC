
#define _CRT_SECURE_NO_WARNINGS 
#define _CRT_NONSTDC_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "simple_linked.h"

int main() {
	ListNode* head = NULL;
	for (int i = 0; i < 10; i++)
		head = insert_first(head, i);
	print_list(head);

	printf("13-1��:\n");
	printf("length = %d\n", get_length(head));// �ۼ��� �Լ�

	printf("13-2��:\n");
	printf("square sum = %d\n", suqare_sum(head)); // �ۼ��� �Լ�

	printf("13-3��:\n");
	print_reverse(head); // �ۼ��� �Լ�

	printf("13-4��:\n");
	head = remove_list(head, 0); print_list(head); // �ۼ��� �Լ�
	head = remove_list(head, 9); print_list(head); // �ۼ��� �Լ�

	printf("13-5��:\n");
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	for (int i = 10; i > 0; i -= 2) head1 = insert_first(head1, i);
	for (int i = 10; i > 5; i -= 3) head2 = insert_first(head2, i);
	print_list(head1);
	print_list(head2);
	ListNode* merged = merge_list(head1, head2); // �ۼ��� �Լ�
	print_list(merged);
	return 0;
}
