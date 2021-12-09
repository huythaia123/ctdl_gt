#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BTNode{
    int data;
    struct BTNode *left;
    struct BTNode *right;
} BTNode;

BTNode *insertBTNode(BTNode *root, int data){
    if(root == NULL){
        BTNode *newNode = malloc(sizeof(BTNode));
        newNode->data  = data;
        newNode->left  = NULL;
        newNode->right = NULL;
        return newNode;
    }
    else if(data == root->data){
        return root;
    }
    else if(data < root->data){
        root->left = insertBTNode(root->left, data);
    }
    else if(data > root->data){
        root->right = insertBTNode(root->right, data);
    }
    return root;
}

bool searchBTNode(BTNode *root, int data){
    BTNode *cur = root;
    if(root == NULL){
        return NULL;
    }
    while(cur != NULL){
        if(data == cur->data){
            return true;
        }
        else if(data < cur->data){
            cur = cur->left;
        }
        else if(data > cur->data){
            cur = cur->right;
        }
    }
}

void preOrder(BTNode *root){
    if(root != NULL){
        printf("%d, ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
    int n;
    BTNode *root = NULL;
    printf("- Nhap vao so luong node: ");
    scanf("%d", &n);

    int data;
    printf("- Nhap vao cac node:\n");
    for(int i = 0; i < n; i++){
        printf("\t+ %d: ", i);
        scanf("%d", &data);
        root = insertBTNode(root, data);
    }
    printf("- Nhap vao gia tri tim: ");
    scanf("%d", &data);
    if(searchBTNode(root, data)){
        printf("True.\n");
    }
    else{
        printf("False.\n");
    }

    return 0;
}