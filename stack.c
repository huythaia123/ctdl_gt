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

typedef struct Stack{
    LinkedList ll;
} Stack;

void printList(Node *head){
    if(head == NULL){
        return;
    }
    Node *cur = head;
    while(cur != NULL){
        printf("%d, ", cur->data);
        cur = cur->next;
    }
}

Node *findNode(Node *head, int index){
    if(head == NULL){
        return NULL;
    }
    if(index < 0){
        return NULL;
    }
    if(index == 0){
        return head;
    }
    Node *cur = head;
    if(index > 0){
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
    if(index == 0 || *ptrHead == NULL){
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
        printf("- Khong the chen.\n");
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
        printf("- Khong the xoa.\n");
    }
}

//////////////////////////////////////
bool isEmptyStack(Stack *s){
    return s->ll.head == NULL;
}

void push(Stack *s, int data){
    insertNode(&(s->ll.head), 0, data);
}

int peek(Stack *s){
    if(!isEmptyStack(s)){
        return s->ll.head->data;
    }
    return 0;
}

int pop(Stack *s){
    int data;
    if(!isEmptyStack(s)){
        data = s->ll.head->data;
        removeNode(&(s->ll.head), 0);
        return data;
    }
    return 0;
}

int main(){
    int n;
    Stack *s;
    s->ll.head = NULL;
    s->ll.tail = NULL;
    printf("- Nhap so luong node: ");
    scanf("%d", &n);
    printf("\n");
    
    int data;
    printf("- Thuc hien push:\n");
    for(int i = 0; i < n; i++){
        printf("\t+ %d: ", i);
        scanf("%d", &data);
        push(s, data);
    }

    printf("- Thuc hien isEmptyStack.\n");
    if(isEmptyStack(s)){
        printf("\t+ Ngan xep rong.\n");
    }
    else{
        printf("\t+ Ngan xep khong rong.\n");
    }

    printf("\n- Thuc hien peek.\n");
    printf("\t+ In ra gia tri dau ngan xep: %d\n\n", peek(s));

    printf("- Thuc hien pop:\n");
    while(!isEmptyStack(s)){
        printf("\t+%d\n", pop(s));
    }
    printf("\n");

    printf("- Thuc hien isEmptyStack.\n");
    if(isEmptyStack(s)){
        printf("\t+ Ngan xep rong.\n");
    }
    else{
        printf("\t+ Ngan xep khong rong.\n");
    }
    return 0;
}