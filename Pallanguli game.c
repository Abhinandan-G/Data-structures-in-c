#include<stdio.h>
#include<stdlib.h>
int ACount=0,BCount=0;
struct node{
  int count;
  struct node *next;
}*head1=NULL,*head2=NULL,*temp1,*temp2,*side1,*side2;
void board(){
  for(int i=0;i<5;i++){  //side 1
    side1=(struct node*)malloc(sizeof(struct node));
    side1->count=5;
    side1->next=NULL;
    if(head1==NULL)
    head1=temp1=side1;
    else{
      temp1->next=side1;
      temp1=side1;
    }
  }
  for(int i=0;i<5;i++){  //side 2
    side2=(struct node*)malloc(sizeof(struct node));
    side2->count=5;
    side2->next=NULL;
    if(head2==NULL)
    head2=temp2=side2;
    else{
      temp2->next=side2;
      temp2=side2;
    }
  }
  temp1->next=head2;
  temp2->next=head1;
}
void putCoinsA(){
  int range=temp1->count;
  temp1->count=0;
  for(int i=0;i<range;i++){
    temp1=temp1->next;
    temp1->count+=1;
  }
  if(temp1->next->count==0){
  ACount=ACount+temp1->next->next->count;
  temp1->next->next->count=0;
  }
  else{
    temp1=temp1->next;
     putCoinsA();
    }
  }
void playerA(int n){
  int i=1;
  temp1=head1;
  while(i<n){
  temp1=temp1->next;
  i++;
  }
  if(temp1->count==0){
  printf("\nPosition invalid....Enter a valid position\n");
  scanf("%d",&n);
  playerA(n);
  }
  else
  putCoinsA();
}
void putCoinsB(){
  int range=temp2->count;
  temp2->count=0;
  for(int i=0;i<range;i++){
    temp2=temp2->next;
    temp2->count+=1;
  }
  if(temp2->next->count==0){
  BCount=BCount+temp2->next->next->count;
  temp2->next->next->count=0;
  }
  else{
    temp2=temp2->next;
     putCoinsB();
    }
  
}
void playerB(int n){
  int i=1;
  temp2=head2;
  while(i<n){
  temp2=temp2->next;
  i++;
  }
  if(temp2->count==0){
  printf("\nPosition invalid....Enter a valid position\n");
  scanf("%d",&n);
  playerB(n);
  }
  else
  putCoinsB();
}
 int checkA(){
   temp1=head1;
   int t=0;
   while(temp1!=head2){
     if(temp1->count!=0){
     t++;
     }
     temp1=temp1->next;
   }
   if(t==0){
     temp2=head2;
   while(temp2!=head1){
     BCount=BCount+temp2->count;
     temp2=temp2->next;
   }
   return 0;
   }
   else
   return 1;
 }
 int checkB(){
   temp2=head2;
   int t=0;
   while(temp2!=head1){
     if(temp2->count!=0)
     t++;
     temp2=temp2->next;
   }
   if(t==0){
     temp1=head1;
     while(temp1!=head2){
       ACount=ACount+temp1->count;
       temp1=temp1->next;
     }
   return 0;
   }
   else
   return 1;
 }
int main(){
  int i=0,b=1,n;
  board();
  while(b==1){
    int c1=checkA();
    int c2=checkB();
    printf("\n\nPlayer A count = %d\nPlayer B count = %d\n",ACount,BCount);
    if(c1==0 || c2==0)
    break;
    else{
    if(i%2==0){
      temp1=head1;
      int j=0;
      printf("\nPlayer A's turn...\nPositions you can select : ");
      while(temp1!=head2){
      if(temp1->count!=0)
      printf("%d ",j+1);
      temp1=temp1->next;
      j++;
    }
    printf("\nEnter the starting position\n");
    scanf("%d",&n);
    playerA(n);
    }
    else if(i%2!=0){
      temp2=head2;
      int j=0;
      printf("\nPlayer B's turn....\nPostions you can select : ");
      while(temp2!=head1){
      if(temp2->count!=0)
      printf("%d ",j+1);
      temp2=temp2->next;
      j++;
      }
    printf("\nEnter the starting position\n");
    scanf("%d",&n);
    playerB(n);
  }
  temp1=head1;
  printf("\nside A : ");
  while(temp1!=head2){
    printf("%d ",temp1->count);
    temp1=temp1->next;
  }
  printf("\n------------------");
  temp2=head2;
  printf("\nside B : ");
  int k=0,arr[5];
  while(temp2!=head1){
    arr[k]=temp2->count;
    temp2=temp2->next;
    k++;
  }
  for(int z=5-1;z>=0;z--){
    printf("%d ",arr[z]);
  }
    }
  i++;
  }
  if(ACount>BCount)
  printf("\nPlayer A wins\n");
  else if(BCount>ACount)
  printf("\nPlayer B wins\n");
  else
  printf("\nMatch draw\n");
  return 0;
}




