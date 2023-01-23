#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left,*right;
}*root=NULL,*newnode,*temp;
void insert(){
	
	struct node *a[50];
	int flag=0,i=-1,j=-1,ch;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element\n");
	scanf("%d",&newnode->data);
	newnode->left=NULL;
	newnode->right=NULL;
	if(root==NULL){
		root=newnode;i++;j++;
		a[i]=newnode;
	}
	printf("\nPress 1 to continue\nPress 2 to exit");
	scanf("%d",&ch);
	while(ch==1){
		printf("Enter the element\n");
		newnode=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&newnode->data);
		newnode->left=NULL;
		newnode->right=NULL;
		i++;
		a[i]=newnode;
		if(flag==0){
			temp=a[j];
			temp->left=newnode;
			flag=1;
		}
		else if(flag==1){
			temp=a[j];
			temp->right=newnode;
			j++;flag=0;
		}
		printf("Press 1 to continue\nPress 2 to exit\n");
		scanf("%d",&ch);
	}
}
void postorder(struct node *w){
	if(w!=NULL){
		postorder(w->left);
		postorder(w->right);
		printf("%d ",w->data);
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
		default: printf("Invalid choice\n");
		break;
	}
}
int main(){
	int a=1,choice;
	while(a){
		printf("\nPress 1 to enter the elements of tree\nPress 2 to traverse\nPress 3 to exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: insert();
			break;
			case 2: traverse();
			break;
			case 3: exit(0);
			break;
			case 4: printf("Invalid input\n");
			break;
		}
	}
	return 0;
}
