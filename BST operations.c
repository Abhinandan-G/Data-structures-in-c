#include<stdio.h>
#include<stdlib.h>
void insert(int n);
void search();
void find_min();
void find_max();
struct node{
	int data;
	struct node *left,*right;
}*root=NULL,*newnode,*temp;
int main(){
	int n;
	printf("Enter the no.of.elements in binary search tree\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	insert(n);
	int a=1,choice;
	while(a){
		printf("Press 1 to search an element\nPress 2 to find the smallest element\nPress 3 to find the greatest element\nPress 4 to exit\n");
		scanf("%d",&choice);
		switch(choice){
		case 1: search();
		break;
		case 2: find_min();
		break;
		case 3: find_max();
		break;
		case 4: exit(0);
		break;
		default : printf("***Invalid input***\n");
		break;
	}
}
}
void insert(int n){
	if(n>0){
		newnode=(struct node*)malloc(sizeof(struct node));
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
				else if(newnode->data==temp->data)
				break;
		}
	}
	insert(n-1);
	}
}
void search(){
	printf("Enter the element to be searched\n");
	int num;
	scanf("%d",&num);
	temp=root;
	while(temp!=NULL){
		if(num==temp->data){
			printf("***Element found***\n");
			break;
		}
		else if(num>temp->data)
		temp=temp->right;
		else if(num<temp->data)
		temp=temp->left;
	}
	if(temp==NULL)
		printf("***Element not found***\n");
}
void find_min(){
	temp=root;
	while(temp->left!=NULL)
		temp=temp->left;
	printf("***The smallest element in the tree is %d***\n",temp->data);
}
void find_max(){
	temp=root;
	while(temp->right!=NULL)
		temp=temp->right;
	printf("***The greatest element in the tree is %d***\n",temp->data);
}
