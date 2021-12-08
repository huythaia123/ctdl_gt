#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
	int data;
	struct Node *next;
} Node;

typedef struct LinkedList{
	Node *head;
	Node *tail;
} LinkedList;

typedef struct Queue{
	LinkedList ll;
} Queue;

void printList(Node *head){
	Node *cur = head;
	if(head == NULL){
		return;
	}
	while(cur != NULL){
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

Node *findNode(Node *head, int index){
	Node *cur = head;
	if(head == NULL){
		return NULL;
	}
	if(index < 0){
		return NULL;
	}
	if(index == 0){
		return head;
	}
	while(index > 0){
		index--;
		cur = cur->next;
		if(cur == NULL){
			return NULL;
		}
	}
	return cur;
}

void insertNode(Node **ptrHead, int index, int data){
	Node *cur, *newNode;
	if(*ptrHead == NULL || index == 0){
		newNode = malloc(sizeof(Node));
		newNode->data = data;
		newNode->next = *ptrHead;
		*ptrHead = newNode;
	}
	else if(cur = findNode(*ptrHead, index-1)){
		newNode = malloc(sizeof(Node));
		newNode->data = data;
		newNode->next = cur->next;
		cur->next = newNode;
	}
	else{
		printf("- khong the chen.\n");
	}
}

void removeNode(Node **ptrHead, int index){
	Node *cur, *pre;
	if(index == 0){
		cur = *ptrHead;
		*ptrHead = cur->next;
		free(cur);
	}
	else if(index > 0){
		pre = findNode(*ptrHead, index-1);
		cur = pre->next;
		pre->next = cur->next;
		free(cur);
	}
	else{
		printf("- Khong the xoa.\n");
	}
}

//////////////////////////////////////
bool isEmptyQueue(Queue *q){
	return q->ll.head == NULL;
}

void enQueue(Queue *q, int data){
	if(q->ll.tail == NULL){
		insertNode(&(q->ll.head), 0, data);
		q->ll.tail = q->ll.head;
	}
	else{
		q->ll.tail->next = malloc(sizeof(Node));
		q->ll.tail = q->ll.tail->next;
		q->ll.tail->data = data;
		q->ll.tail->next = NULL;
	}
}

int peek(Queue *q){
	if(!isEmptyQueue(q)){
		return q->ll.head->data;
	}
	return 0;
}

int deQueue(Queue *q){
	int data;
	if(!isEmptyQueue(q)){
		data = q->ll.head->data;
		removeNode(&(q->ll.head), 0);
		return data;
	}
	return 0;
}

int main(){
	int n, data;
	Queue *q;
	q->ll.tail = NULL;
	q->ll.head = NULL;
	printf("- Nhap vao so luong node: ");
	scanf("%d", &n);

	printf("- Thuc hien enQueue:\n");
	for(int i = 0; i < n; i++){
		printf(" + %d: ", i);
		scanf("%d", &data);
		enQueue(q, data);
	}

	printf("- Thuc hien peek.\n");
	printf(" + In ra gia tri dau hang doi: %d\n", peek(q));

	// printf("- Thuc hien deQueue:\n");
	// while(!isEmptyQueue(q)){
	// 	printf("%d, ", deQueue(q));
	// }
	// printf("\n");

	printf("- Thuc hien isEmptyQueue.\n");
	if(isEmptyQueue(q)){
		printf(" + Hang doi rong.\n");
	}
	else{
		printf(" + Hang doi khong rong.\n");
	}
	return 0;
}