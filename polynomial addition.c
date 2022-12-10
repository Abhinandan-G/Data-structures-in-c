#include<stdio.h>
#include<stdlib.h>
struct node{
  int coeff,expo;
  struct node *next;
}*head1=NULL,*head2=NULL,*head3=NULL,*temp1,*temp2,*temp3,*poly1,*poly2,*result;
void create_poly_1(){
  int a=1;
  while(a==1){
  poly1=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter the coeffient : ");
  scanf("%d",&poly1->coeff);
  printf("\nEnter the exponential : ");
  scanf("%d",&poly1->expo);
  poly1->next=NULL;
  if(head1==NULL){
  head1=poly1;
  temp1=head1;
  }
  else{
    temp1->next=poly1;
    temp1=temp1->next;
  }
  printf("\nPress 1 to insert the next term of polynomial 1\nPress 2 to exit\n");
  scanf("%d",&a);
  }
}
void create_poly_2(){
  int a=1;
  while(a==1){
  poly2=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter the coeffient : ");
  scanf("%d",&poly2->coeff);
  printf("\nEnter the exponential : ");
  scanf("%d",&poly2->expo);
  poly2->next=NULL;
  if(head2==NULL){
  head2=poly2;
  temp2=head2;
  }
  else{
    temp2->next=poly2;
    temp2=temp2->next;
  }
  printf("\nPress 1 to insert the next term of polynomial 2\nPress 2 to exit\n");
  scanf("%d",&a);
  }
}
void create_result(int coeffient,int exponential){
  result=(struct node*)malloc(sizeof(struct node));
  result->coeff=coeffient;
  result->expo=exponential;
  result->next=NULL;
  if(head3==NULL)
  head3=temp3=result;
  else{
    temp3->next=result;
    temp3=result;
  }
}
void add(){
  temp1=head1;
  temp2=head2;
  while(temp1!=NULL && temp2!=NULL){
    if(temp1->expo == temp2->expo){
      create_result(temp1->coeff+temp2->coeff,temp1->expo);
      temp1=temp1->next;
      temp2=temp2->next;
    }
    else if(temp1->expo > temp2->expo){
      create_result(temp1->coeff,temp1->expo);
      temp1=temp1->next;
    }
    else if(temp2->expo > temp1->expo){
      create_result(temp2->coeff,temp2->expo);
      temp2=temp2->next;
    }
  }
    while(temp1!=NULL){
      create_result(temp1->coeff,temp1->expo);
      temp1=temp1->next;
    }
    while(temp2!=NULL){
      create_result(temp2->coeff,temp2->expo);
      temp2=temp2->next;
    }
 }
 void display_result(){
   if(head1==NULL && head2==NULL)
   printf("\nThe result is empty\n");
   else{
    temp3=head3;
    while(temp3!=NULL){
      printf("%dx^%d-->",temp3->coeff,temp3->expo);
      temp3=temp3->next;
    }
    printf("NULL");
 }
 }
void main(){
  int c,option;
  while(c){
    printf("\nPress 1 to create polynomial 1\nPress 2 to create polynomial 2\nPress 3 to add the polynomials\nPress 4 to display the result\nPress 5 to exit\n");
    scanf("%d",&option);
    switch(option){
      case 1: create_poly_1();
      break;
      case 2: create_poly_2();
      break;
      case 3: add();
      break;
      case 4: display_result();;
      break;
      case 5: exit(0);
      break;
    }
  }
}



