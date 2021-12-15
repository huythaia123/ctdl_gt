// Linked List
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
} Node;

typedef struct LinkedList{
	Node *head;
	Node *tail;
} LinkedList;

void printList(Node *head){
	Node *cur = head;
	if(head == NULL){
		return;
	}
    int i = 0;
	while(cur != NULL){
		printf("\t+ %d: %d\n", i, cur->data);
		cur = cur->next;
        i++;
	}
    printf("\n");
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
		printf("\t! khong the chen.\n");
	}
}

void removeNode(Node **ptrHead, int index){
    Node *cur, *pre;
    if(index == 0){
        cur = *ptrHead;
        *ptrHead = cur->next;
        free(cur);
    }
    else if(pre = findNode(*ptrHead, index-1)){
        cur = pre->next;
        pre->next = cur->next;
        free(cur);
    }
    else{
        printf("\t! Khong the xoa.\n");
    }
}

int main(){
    int n, size = 0, data, index;
    LinkedList *ll;
    ll->head = NULL;
    ll->tail = NULL;

    printf("- Nhap so luong node: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("\t+ %d: ", i);
        scanf("%d", &data);
        insertNode(&(ll->head), size, data);
        size++;
    }
    printf("\n");

    printf("- In ra dslk:\n");
    printList(ll->head);

    printf("- Nhap vi tri node can tim: ");
    scanf("%d", &index);
    if(findNode(ll->head, index) == NULL){
        printf("\t+ Khong co node can tim.\n\n");
    }
    else{
        printf("\t+ Gia tri node can tim: %d\n\n", findNode(ll->head, index)->data);
    }

    printf("- Nhap vi tri can chen node: ");
    scanf("%d", &index);
    printf("- Nhap gia tri node moi: ");
    scanf("%d", &data);
    insertNode(&(ll->head), index, data);
    printf("\t! Updata:\n");
    printList(ll->head);

    printf("- Nhap vi tri node can xoa: ");
    scanf("%d", &index);
    removeNode(&(ll->head), index);
    printf("\t! Updata:\n");
    printList(ll->head);

    return 0;
}