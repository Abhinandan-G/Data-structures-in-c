#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
};
struct node *top=NULL,*temp,*newnode;
void push(){
  newnode=(struct node*)malloc(sizeof(struct node));
  scanf("%d",&newnode->data);
  newnode->next=top;
  top=newnode;
  printf("Node is inserted\n");
}
void pop(){
  int n;
  temp=top;
  top=temp->next;
  n=temp->data;
  free(temp);
  printf("Popped element is %d\n",n);
}
void display(){
  temp=top;
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
  }
}
int main(){
  int choice,i=1;
  while(i)
  {
    printf("\nPress 1 to push\nPress 2 to pop\nPress 3 to display\nPress 4 to exit\n");
    scanf("%d",&choice);
    switch(choice){
      case 1:push();
      break;
      case 2:pop();
      break;
      case 3:display();
      break;
      case 4: exit(0);
      break;
      default : printf("\nInvalid input\n");
      break;
    }
    
    }
  }

