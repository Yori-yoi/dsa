#include<stdio.h>
#include<stdlib.h>

//node structure
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	};

//preorder traversal of binary tree
void preorder(struct Node * root){
	if (root != NULL)
	{
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

//creation of tree nodes using function
struct Node* create_node(int data){
	struct Node* ptr= (struct Node*)malloc(sizeof(struct Node));
	ptr->left=NULL;
	ptr->right=NULL;
	ptr->data=data;
	return ptr;
	}

//postorder traversal of binary tree
void postorder(struct Node * root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}

//inorder traversal of binary tree
void inorder(struct Node* root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

int isBST(struct Node* root){
	struct Node * prev = NULL;
	if(root!=NULL){
		if (!isBST(root->left)){
			return 0;
		}
		if(prev!= NULL && root->data<=prev->data){
			return 0;
		}
		prev=root;
		return isBST(root->right);
		

	}
	else{
		return 1;
	}
}
struct Node * BSTsearch(struct Node*root, int key){
	if(root==NULL){
		printf("Not found");
		return NULL;

	}
	if(root->data==key){
		printf("Found");
		return root;
	}
	else if(key>root->data){
		return BSTsearch(root->right,key);
	}
	else{
		return BSTsearch(root->left,key);
	}
}

struct Node * BSTitersearch(struct Node*root,int key){
	while(root!=NULL){
			if(root->data==key){
				printf("Found");
				return root;
			}
			else if(key>root->data){
				root = root->right;
			}
			else{
				root= root->left;
			}
		}
	return NULL;
}
int main(){
	struct Node *p1, *p2, *p3;
	p1=create_node(3);
	p2=create_node(4);
	p3=create_node(5);
	p1->left=p2;
	p2->right=p3;
	preorder(p1);
	postorder(p1);
	inorder(p1);
	return 0;
}


