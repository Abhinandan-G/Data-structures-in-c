#include <stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *left,*right;
}*head=NULL,*temp,*newnode,*nextnode;
void insertatfirst(){
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter the data to be inserted\n");
  scanf("%d",&newnode->data);
  newnode->right=NULL;
  newnode->left=NULL;
  if(head==NULL)
  head=temp=newnode;
  else{
    newnode->right=head;
    head->left=newnode;
    head=newnode;
  }
}
void insertatmid(){
  int pos,i=0;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter the position to be inserted\n");
  scanf("%d",&pos);
  printf("Enter the data to be inserted\n");
  scanf("%d",&newnode->data);
  newnode->right=NULL;
  newnode->left=NULL;
  temp=head;
  while(i<pos-2){
    temp=temp->right;
    i++;
  }
  newnode->right=temp->right;
  newnode->left=temp;
  temp->right=newnode;
  newnode->right->left=newnode;
}
void insertatlast(){
  if(head==NULL)
  insertatfirst();
  else{
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("Enter the data to be inserted\n");
  scanf("%d",&newnode->data);
  newnode->right=NULL;
  newnode->left=NULL;
  temp=head;
  while(temp->right!=NULL){
    temp=temp->right;
  }
  newnode->left=temp;
  temp->right=newnode;
}
}
void insert(){
  printf("\nPress 1 to insert at first\nPress 2 to insert at middle\nPress 3 to insert at last\n");
  int option;
  scanf("%d",&option);
  switch(option){
    case 1: insertatfirst();
    break;
    case 2: insertatmid();
    break;
    case 3: insertatlast();
    break;
    default: printf("\nInvalid input\n");
    break;
  }
}
void deleteatfirst(){
  if(head->right==NULL){
  free(head);
  head=NULL;
  }
  else{
  temp=head;
  head=head->right;
  head->left=NULL;
  free(temp);
  }
}
void deleteatmid(){
  int pos,i=0;
  printf("\nEnter the position to be deleted\n");
  scanf("%d",&pos);
  temp=head;
  while(i<pos-1){
    nextnode=temp;
    temp=temp->right;
    i++;
  }
  nextnode->right=temp->right;
  temp->right->left=nextnode;
  
  free(temp);
}
void deleteatend(){
  temp=head;
  while(temp->right->right!=NULL){
    temp=temp->right;
  }
  nextnode=temp->right;
  temp->right=NULL;
  free(nextnode);
}
void delete(){
  printf("\nPress 1 to delete at front\nPress 2 to delete at mid\nPress 3 to delete at last\n");
  int choice;
  scanf("%d",&choice);
  switch(choice){
    case 1: deleteatfirst();
    break;
    case 2: deleteatmid();
    break;
    case 3: deleteatend();
    break;
    default: printf("\nInvalid input\n");
    break;
  }
}
void display(){
  if(head==NULL)
  printf("\nEmpty list\n");
  else{
  temp=head;
  while(temp!=NULL){
    printf("%d<--->",temp->data);
    temp=temp->right;
  }
  printf("NULL\n");
}
}
int main()
{
  int c,option;
  printf("***You are creating a doubly linked list***");
  while(c){
    printf("\nPress 1 to insert the node\nPress 2 to delete the node\nPress 3 to display\nPress 4 to exit\n");
    scanf("%d",&option);
    switch(option){
      case 1: insert();
      break;
      case 2: delete();
      break;
      case 3: display();
      break;
      case 4: exit(0);
      break;
      default: printf("\nInvalid input\n");
      break;
    }
  }

    return 0;
}


