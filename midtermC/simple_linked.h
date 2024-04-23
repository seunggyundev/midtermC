#ifndef __SIMPLE_LINKED__
#define __SIMPLE_LINKED__

typedef int element;
typedef struct ListNode { 	// 노드 타입
	element data;
	struct ListNode* link;
} ListNode;


void error(char* message);
ListNode* insert_first(ListNode* head, int value);
ListNode* insert(ListNode* head, ListNode* pre, element value);
ListNode* delete_first(ListNode* head);
ListNode* delete(ListNode* head, ListNode* pre);
void print_list(ListNode* head);
// 새로 추가한 내용들
int get_length(ListNode* head);
int suqare_sum(ListNode* head);
void print_reverse(ListNode* head);
ListNode* remove_list(ListNode* head, int data);
ListNode* merge_list(ListNode* head1, ListNode* head2);
#endif
