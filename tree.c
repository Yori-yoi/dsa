#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	};
void preorder(struct Node * root){
	if (root != NULL)
	{
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
struct Node* create_node(int data){
	struct Node* ptr= (struct Node*)malloc(sizeof(struct Node));
	ptr->left=NULL;
	ptr->right=NULL;
	ptr->data=data;
	return ptr;
	}
int main(){
	struct Node *p1, *p2, *p3;
	p1=create_node(3);
	p2=create_node(4);
	p3=create_node(5);
	p1->left=p2;
	p2->right=p3;
	preorder(p1);
	return 0;
}

