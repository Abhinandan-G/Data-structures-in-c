#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
}*front=NULL,*rear=NULL,*top=NULL,*newnode,*temp;
void enqueue(int x){
  newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=x;
  newnode->next=NULL;
  if(front==NULL&&rear==NULL)
    front=rear=newnode;
  else{
    rear->next=newnode;
    rear=newnode;
  }
}
void reverse(){
  if(front==NULL && rear==NULL)
  printf("\nEmpty queue\n");
  else{
  while(front!=NULL){
   newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=front->data;;
    newnode->next=NULL;
    if(top==NULL){
      top=newnode;
    }
    else{
      newnode->next=top;
      top=newnode;
    }
    temp=front;
    front=front->next;
    free(temp);
}
}
  front=rear=NULL;
  while(top!=NULL){
    enqueue(top->data);
    top=top->next;
  }
}
void display(){
  if(front==NULL)
  printf("\nEmpty queue\n");
  else{
   temp=front;
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
  }
  }
}
int main(){
  int c,option,x;
  while(c){
    printf("\nPress 1 to insert the elements of queue\nPress 2 to reverse the queue\nPress 3 to display\nPress 4 to exit\n");
    scanf("%d",&option);
    switch(option){
      case 1: {
              printf("\nEnter the data to be inserted\n");
              scanf("%d",&x);
              enqueue(x);
    }
      break;
      case 2: reverse();
      break;
      case 3: display();
      break;
      case 4: exit(0);
      break;
    }
  }
}
