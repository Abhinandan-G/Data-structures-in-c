#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left,*right;
}*root=NULL,*newnode,*temp,*temp1,*prev1,*prev;

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
void delete_node(){
	int num,swap;
	printf("Enter the element to be deleted\n");
	scanf("%d",&num);
	temp=root;
	while(temp!=NULL){
		if(num>temp->data){
			prev=temp;
			temp=temp->right;
		}
		else if(num<temp->data){
			prev=temp;
			temp=temp->left;
		}
		else if(temp->data==num){
			if(temp->left!=NULL && temp->right!=NULL){
				temp1=temp->left;
				while(temp1->right!=NULL){
			    prev1=temp1;
				temp1=temp1->right;
			}
			swap=temp1->data;
			temp1->data=temp->data;
			temp->data=swap;
			prev1->right=NULL;
			free(temp1);
			}
			else if(temp->left==NULL && temp->right==NULL){
				if(prev->left==temp)
				prev->left=NULL;
				else if(prev->right==temp)
				prev->right=NULL;
				free(temp);
			}
			else if(temp->left==NULL && temp->right!=NULL){
				swap=temp->right->data;
				temp->right->data=temp->data;
				temp->data=swap;
				temp->right=NULL;
			}
			else if(temp->left!=NULL && temp->right==NULL){
				swap=temp->left->data;
				temp->left->data=temp->data;
				temp->data=swap;
				temp->left=NULL;
			}
		break;
	}
	}
}

int main(){
	int n;
	printf("Enter the no.of.elements in binary search tree\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	insert(n);
	int a=1,choice;
	while(a){
		printf("Press 1 to search an element\nPress 2 to find the smallest element\nPress 3 to find the greatest element\nPress 4 to delete\nPress 5 to traverse\nPress 6 to exit\n");
		scanf("%d",&choice);
		switch(choice){
		case 1: search();
		break;
		case 2: find_min();
		break;
		case 3: find_max();
		break;
		case 4: delete_node();
		break;
		case 5: traverse();
		break;
		case 6: exit(0);
		break;
		default : printf("***Invalid input***\n");
		break;
	}
}
}