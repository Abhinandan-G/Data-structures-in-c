#include<stdio.h>
void create_table(int n,int size,int *table){
    int temp,loc;
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        loc=temp%size;
        if(*(table+loc)==0)
            *(table+loc)=temp;
        else{
            for(int j=1;j>0;j++){
                loc=((temp%size)+j)%size;
                if(*(table+loc)==0){
                    *(table+loc)=temp;
                    break;
                }
            }
        }
    }
}
void print_table(int size, int *table){
    for(int i=0;i<size;i++){
        printf("%d ",*(table+i));
    }
    printf("\n");
}
int main(){
    int num,size;
    printf("Enter the number of elements\n");
    scanf("%d",&num);
    printf("Enter the table size\n");
    scanf("%d",&size);
   int table[size];
    for(int i=0;i<size;i++)
        table[i]=0;
    printf("Enter the elements\n");
    create_table(num,size,table);
    print_table(size,table);
}