#include<stdio.h>
#include<stdlib.h>

typedef struct __btnode{
	int data;
	struct __btnode *left;
	struct __btnode *right;
} BTNode;

BTNode *insertBTNode(BTNode *root, int data){
	if(root == NULL){
		BTNode *newNode = malloc(sizeof(BTNode));
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	if(data <= root->data){
		root->left = insertBTNode(root->left, data);
	}
	else if(data > root->data){
		root->right = insertBTNode(root->right, data);
	}
	return root;
}

void preOrder(BTNode *root){
	if(root != NULL){
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(BTNode *root){
	if(root != NULL){
		inOrder(root->left);
		printf("%d ", root->data);
		inOrder(root->right);
	}
}

void postOrder(BTNode *root){
	if(root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->data);
	}
}

int main(){
	int n, data;
	BTNode *root = NULL;
	printf("- Nhap vao so luong node: ");
	scanf("%d", &n);
	printf("- Thuc hien insertNode:\n");
	for(int i = 0; i < n; i++){
        printf("\t%d: ", i);
		scanf("%d", &data);
		root = insertBTNode(root, data);
	}
	printf("- Duyet preOrder : ");
	preOrder(root);
	printf("\n");

    printf("- Duyet inOrder  : ");
	inOrder(root);
	printf("\n");
    
    printf("- Duyet postOrder: ");
	postOrder(root);
	printf("\n");

	return 0;
}