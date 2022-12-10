#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next;
}*head,*temp,*new,*prev;
void insert_at_front(){
  printf("\nEnter the element needed to be inserted at the beginning : ");
 new=(struct node*)malloc(sizeof(struct node));
 scanf("%d",&new->data);
 new->next=head;
 head=new;
}
void insert_in_middle(){
  int pos,i=1;
  if(head==NULL)
  printf("\nThe list is empty\n");
  else if(head->next==NULL)
  printf("\nThis operation cannot be performed because there is only one node\n");
  else{
  printf("\nEnter the position to be inserted : ");
  scanf("%d",&pos);
      temp=head;
      while(i<pos-1){
        temp=temp->next;
        i++;
      }
      new=(struct node *)malloc(sizeof(struct node));
      printf("\nEnter the element to be inserted : ");
      scanf("%d",&new->data);
      new->next=temp->next;
      temp->next=new;
  }
}
void insert_at_last(){
  if(head==NULL){
    insert_at_front();
  }
  else{
  printf("\nEnter the element needed to be inserted at the last : ");
 new=(struct node*)malloc(sizeof(struct node));
 scanf("%d",&new->data);
 new->next=NULL;
 temp=head;
 while(temp->next!=NULL){
   temp=temp->next;
 }
 temp->next=new;
  }
}
void display(){
  if(head==NULL)
  printf("\nThe list is empty\n");
  else{
    printf("\nThe elements are : ");
  temp=head;
    while(head!=NULL){
      printf("%d-->",temp->data);
      if(temp->next==NULL)
      break;
      else
      temp=temp->next;
    }
    printf("NULL\n");
}
}
void delete_at_front(){
  if(head==NULL)
    printf("\nInvalid operation because list is empty\n");
  else{
   temp=head;
  head=temp->next;
  free(temp);
  }
}
void delete_at_middle(){
  if(head==NULL)
    printf("\nInvalid operation because list is empty\n");
    else{
  int pos,i=1;
  printf("\nEnter the position to be deleted : ");
  scanf("%d",&pos);
  temp=head;
  while(i<=pos-1){
    prev=temp;
    temp=temp->next;
    i++;
  }
  prev->next=temp->next;
  free(temp);
    }
}
void delete_at_end(){
  if(head==NULL)
    printf("\nInvalid operation because list is empty\n");
  else if(head->next==NULL){
    free(head);
  }
  else{
  temp=head;
  while(temp->next!=NULL){
    prev=temp;
    temp=temp->next;
  }
  prev->next=NULL;
  free(temp);
  }
}
void insert(){
  int select;
  printf("\nPress 1 to insert at front\nPress 2 to insert in middle\nPress 3 to insert at last\n");
  scanf("%d",&select);
  switch(select){
    case 1: insert_at_front();
    break;
    case 2: insert_in_middle();
    break;
    case 3: insert_at_last();
    break;
    default: printf("\nInvalid input\n");
    break;
  }
}
void delete(){
  int select;
  printf("\nPress 1 to delete at front\nPress 2 to delete in middle\nPress 3 to delete at last\n");
  scanf("%d",&select);
  switch(select){
    case 1: delete_at_front();
    break;
    case 2: delete_at_middle();
    break;
    case 3: delete_at_end();
    break;
    default: printf("\nInvalid input\n");
    break;
  }
}
void main(){
  int num,option;
  while(num){
  printf("\nPress 1 to insert\nPress 2 to delete\nPress 3 to display\nPress 4 to exit\n");
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
      }
  }
}