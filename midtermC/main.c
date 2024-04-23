
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

	printf("13-1번:\n");
	printf("length = %d\n", get_length(head));// 작성할 함수

	printf("13-2번:\n");
	printf("square sum = %d\n", suqare_sum(head)); // 작성할 함수

	printf("13-3번:\n");
	print_reverse(head); // 작성할 함수

	printf("13-4번:\n");
	head = remove_list(head, 0); print_list(head); // 작성할 함수
	head = remove_list(head, 9); print_list(head); // 작성할 함수

	printf("13-5번:\n");
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	for (int i = 10; i > 0; i -= 2) head1 = insert_first(head1, i);
	for (int i = 10; i > 5; i -= 3) head2 = insert_first(head2, i);
	print_list(head1);
	print_list(head2);
	ListNode* merged = merge_list(head1, head2); // 작성할 함수
	print_list(merged);
	return 0;
}
