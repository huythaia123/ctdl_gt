#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct listnode{
    int data;
    struct listnode *next;
} ListNode;

typedef struct linkedlist{
    ListNode *head;
    ListNode *tail;
    int size;
} LinkedList;

typedef struct queue{
    LinkedList ll;
} Queue;

// cac ham dslk
void printList(ListNode *head){
    ListNode *cur = head;
    if(head = NULL){
        return;
    }
    while(cur != NULL){
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

ListNode *findNode(ListNode *head, int index){
    ListNode *cur = head;
    if(cur == NULL || index == 0){
        return NULL;
    }
    if(index == 1){
        return cur;
    }
    while(index > 1){
        cur = cur->next;
        if(cur == NULL){
            return NULL;
        }
        --index;
    }
    return cur;
}

void insertNode(ListNode **ptrHead, int insert_i, int value){
    ListNode *cur, *newNode;
    newNode = malloc(sizeof(ListNode));
    newNode->data = value;
    if(*ptrHead == NULL || insert_i == 1){
        newNode->next = *ptrHead;
        *ptrHead = newNode;
    }
    else if((cur = findNode(*ptrHead, insert_i-1)) != NULL){
        newNode->next = cur->next;
        cur->next = newNode;
    }
    else{
        return;
    }
}

void removeNode(ListNode **ptrHead, int index){
    ListNode *cur, *pre;
    if(index == 0){
        cur = *ptrHead;
        *ptrHead = cur->next;
        free(cur);
    }
    else if(index > 0) {
        pre = findNode(*ptrHead, index-1);
        cur = pre->next;
        pre->next = cur->next;
        free(cur);
    }
    else{
        printf("\t(!) Khong the xoa node %d\n", index);
    }
}

// cac ham hang doi
bool isEmptyQueue(Queue *q){
    return q->ll.head == NULL;
}

int peek(Queue *q){
    if(q->ll.head != NULL){
        return q->ll.head->data;
    }
}

int main(){
    int n;
    Queue *q;

    return 0;
}
