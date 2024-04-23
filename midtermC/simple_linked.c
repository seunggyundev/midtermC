#define _CRT_SECURE_NO_WARNINGS 
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "simple_linked.h"

// 오류 처리 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;					// (2)
	p->link = head;	// 헤드 포인터의 값을 복사	//(3)
	head = p;	// 헤드 포인터 변경		//(4)
	return head;	// 변경된 헤드 포인터 반환
}

// 노드 pre 뒤에 새로운 노드 삽입
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

// pre가 가리키는 노드의 다음 노드를 삭제한다. 
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

// 스택 길이를 구하는 함수
int get_length(ListNode* head) {
    int length = 0; // 노드의 개수를 세는 변수
    for (ListNode* p = head; p != NULL; p = p->link)
        length++; // 노드를 순회하며 개수를 셈
    return length; // 개수(길이) 반환
}

// 홀수 값의 제곱 합을 구하는 함수
int suqare_sum(ListNode* head) {
    int sum = 0; // 제곱의 합을 저장하는 변수
    for (ListNode* p = head; p != NULL; p = p->link) {
        if (p->data % 2 != 0) // 현재 노드의 값이 홀수인지 확인
            sum += p->data * p->data; // 홀수이면 제곱 후 더함
    }
    return sum; 
}

// 스택의 모든 요소를 역순으로 출력하는 재귀 함수
void print_reverse(ListNode* head) {
    if (head == NULL)
        return;
    print_reverse(head->link); // 다음 노드로
    printf("%d ", head->data);
}

// 주어진 데이터 값을 가진 노드를 스택에서 삭제하는 함수
ListNode* remove_list(ListNode* head, int data) {
    ListNode* now = head, * previous = NULL;
    while (now != NULL && now->data != data) {
        previous = now; // 현재 노드를 previous에 저장
        now = now->link; // 다음 노드로 이동
    }
    if (now != NULL) { // 삭제할 노드를 찾은 경우
        if (previous == NULL) // head를 삭제하는 경우
            head = delete_first(head); // 1번 노드를 삭제
        else
            head = delete(head, previous); // 주어진 노드를 삭제
    }
    return head; 
}

// 두 스택을 합치는 함수
ListNode* merge_list(ListNode* head1, ListNode* head2) {
    if (head1 == NULL) return head2; // 1번 스택이 비어있으면 2번 스택 반환
    if (head2 == NULL) return head1; // 2번 스택이 비어있으면 1번 스택 반환

    ListNode* mergedHead = NULL; // 병합스택의 헤드
    if (head1->data < head2->data) { // 작은 값을 가진 노드를 병합스택의 헤드로 설정
        mergedHead = head1;
        mergedHead->link = merge_list(head1->link, head2); // 나머지 스택 합치기
    }
    else {
        mergedHead = head2;
        mergedHead->link = merge_list(head1, head2->link); // 나머지 스택 합치기
    }
    return mergedHead;
}

// 스택에 할당된 메모리 해제
void free_stack(ListNode* head) {
    ListNode* now = head;
    ListNode* next;

    while (now != NULL) {
        next = now->link;
        free(now);
        now = next;
    }
}
