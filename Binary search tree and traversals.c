#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left,*right;
}*root=NULL,*newnode,*temp;
void insert();
void preorder(struct node *w);
void postorder(struct node *w);
void inorder(struct node *w);
void traverse();
int main(){
	int choice,a=1;
	while(a){
		printf("Press 1 to insert elements\nPress 2 to traverse\nPress 3 to exit\n");
		scanf("%d",&choice);
		switch(choice){
		case 1: insert();
		break;
		case 2: traverse();
		break;
		case 3: exit(0);
		break;
		default: printf("Invalid input\n");
		break;
	}
}
}
void insert(){
	int a;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element\n");
	scanf("%d",&newnode->data);
	newnode->left=NULL;
	newnode->right=NULL;
	if(root==NULL)
		root=newnode;
	else{
		temp=root;
		while(temp!=NULL){
			if(newnode->data<temp->data){
				if(temp->left!=NULL)
					temp=temp->left;
				else{
					temp->left=newnode;
					break;
				}
			}
			else if(newnode->data>temp->data){
				if(temp->right!=NULL)
					temp=temp->right;
				else{
					temp->right=newnode;
					break;
				}
			}
		}
	}
	printf("Press 1 to continue\nPress 2 to return\n");
	scanf("%d",&a);
	if(a==1)
		insert();
}
void traverse(){
	int choice;
	printf("Press 1 for preorder\nPress 2 for inorder\nPress 3 for postorder\n");
	scanf("%d",&choice);
	switch(choice){
		case 1: preorder(root);
		break;
		case 2: inorder(root);
		break;
		case 3: postorder(root);
		break;
		default: printf("Invalid input\n");
		break;
	}
}
void inorder(struct node *w){
	if(w!=NULL){
		inorder(w->left);
		printf("%d ",w->data);
		inorder(w->right);
	}
}
void preorder(struct node *w){
	if(w!=NULL){
		printf("%d ",w->data);
		preorder(w->left);
		preorder(w->right);
	}
}
void postorder(struct node *w){
	if(w!=NULL){
		postorder(w->left);
		postorder(w->right);
		printf("%d ",w->data);
	}
}
