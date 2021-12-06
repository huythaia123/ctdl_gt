#include<stdio.h>
#include<stdlib.h>

typedef struct listnode{
    int data;
    struct listnode *next;
} ListNode;

typedef struct LinkedList{
    ListNode *head;
    ListNode *tail;
} LinkedList;

void xoabodem(){
   int ch;
   while ((ch=getchar()) !='\n' && ch!=EOF);
}

void menu(){
    printf("==== Cac thao tac dslk ====\n");
    printf("(1) In ra dslk.\n");
    printf("(2) Tao dslk.\n");
    printf("(3) Tim node trong dslk.\n");
    printf("(4) Them vao dslk.\n");
    printf("(5) Xoa khoi dslk.\n");
    printf(" (+) An phim khac de thoat.\n");
    printf("----------------------------------------------------\n");
    printf(" (+) Chon chuong trinh: ");
}

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

void insertNode(ListNode **ptrHead, int index, int value){
    ListNode *cur, *newNode;
    newNode = malloc(sizeof(ListNode));
    newNode->data = value;
    if(*ptrHead == NULL || index == 1){
        newNode->next = *ptrHead;
        *ptrHead = newNode;
    }
    else if((cur = findNode(*ptrHead, index-1)) != NULL){
        newNode->next = cur->next;
        cur->next = newNode;
    }
    else{
        printf("\t(+) Khong the chen node vao index = %d", index);
    }
}

void creatrListNode(LinkedList *ll, int value){
    if(ll->tail == NULL){
        insertNode( &(ll->head), 0, value);
        ll->tail = ll->head;
    }
    else{
        ListNode *newNode = malloc(sizeof(ListNode));
        newNode->data = value;
        newNode->next = NULL;
        ll->tail->next = newNode;
        ll->tail = newNode;
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

int main(){
    int n, lc, value, index;
    char ch;
    ListNode *kq_fn;
    LinkedList ll;
    ll.head = NULL;
    ll.tail = NULL;
    do{
        system("clear");
        system("cls");
        menu();
        scanf("%d", &lc);
        switch(lc){
            case 1:
                if(ll.head != NULL){
                    printf("\t(+) In dslk: ");
                    printList(ll.head);
                }
                else{
                    printf("\t(+) Dslk rong.\n");
                }
                break;
            case 2:
                if(ll.head != NULL){
                    printf("\t(+) Dslk da ton tai.\n");
                }
                else{
                    printf("\t(+) Tao dslk:\n");
                    printf("\t(+) Nhap so luong node: ");
                    scanf("%d", &n);
                    for(int i = 0; i < n; i++){
                        printf("\t(+) Node %d: ", i+1);
                        scanf("%d", &value);
                        creatrListNode(&ll, value);
                    }
                }
                break;
            case 3:
                if(ll.head == NULL){
                    printf("\t(+) DSLK rong.\n");
                }
                else{
                    printf("\t(+) Nhap vi tri node muon tim: ");
                    scanf("%d", &index);
                    kq_fn = findNode(ll.head, index);
                    if(kq_fn != NULL){
                        printf("\t(+) Node %d: %d\n", index, kq_fn->data);
                    }
                    else if(kq_fn == NULL){
                        printf("\t(!) Khong co vi tri can tim.\n");
                    }
                }
                break;
            case 4:
                if(ll.head == NULL){
                    printf("\t(+) Chua co dslk.\n");
                }
                else{
                    printf("\t(+) Them vao dslk\n");
                    printf("\t(+) Nhap vi tri node can them: ");
                    scanf("%d", &index);
                    printf("\t(+) Nhap gia tri node: ");
                    scanf("%d", &value);
                    insertNode(&ll.head, index, value);
                }
                break;
            case 5:
                if(ll.head == NULL){
                    printf("\t(+) Dslk rong.\n");
                }
                else{
                    printf("\t(+) Xoa node khoi dslk\n");
                    printf("\t(+) Nhap vi tri node muon xoa: ");
                    scanf("%d", &index);
                    removeNode(&ll.head, index);
                    printf("\t(+) Da xoa node %d.\n", index);
                }
                break;
            default:
                printf("\t(+) Thoat!\n");
        }
        printf("(!) Ban co muon tiep tuc chuong trinh khong (y/n): ");
        xoabodem();
        scanf("%c",&ch);
    } while(ch == 'y' || ch == 'Y');
    return 0;
}