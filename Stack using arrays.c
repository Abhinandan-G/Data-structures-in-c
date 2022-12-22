#include<stdio.h>
#include<stdlib.h>
int top=-1,x[50];
void push()
{
  int num;
  printf("\nEnter the element\n");
 scanf("%d",&num);
  top++;
  x[top]=num;
  printf("%d pushed to stack\n",num);
}
void display(){
  for(int i=top;i>=0;i--){
    printf("%d ",x[i]);
  }
}
void pop(){
  int num=x[top];
   top--;
   printf("%d popped from stack\n",num);
}
void no_of_elements(){
  printf("%d elements in stack\n",top+1);
}
int main()
{
  int i=1,choice;
  while(i){
    printf("\nPress 1 to push elements\nPress 2 to pop elements\nPress 3 to display\nPress 4 to exit\n");
  scanf("%d",&choice);
  switch(choice){
    case 1 : push();
    break;
    case 2: pop();
    break;
    case 3 : display();
    break;
    case 4 : exit(0);
    break;
  }
  
  }
  return 0;
}
