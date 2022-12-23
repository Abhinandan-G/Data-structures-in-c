#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main()
{
    struct node *head,*temp,*newnode,*prevnode,*nextnode,*currentnode;
    head=NULL;
    int n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(int i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&(newnode->data));
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    prevnode=NULL;
    currentnode=head;
    nextnode=head;
    while(nextnode!=NULL){
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    head=prevnode;
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }

    return 0;
}