#include<stdio.h>
void create_table(int n,int size,int *table){
    int temp,h1_key,h2_key,loc;
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        loc=temp%size;
        if(*(table+loc)==0)
            *(table+loc)=temp;
        else{
            h2_key=7-(temp%7);
            for(int j=1;j>0;j++){
                loc=(loc+(j*h2_key))%size; //  hash2(key) = PRIME – (key % PRIME) 
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
