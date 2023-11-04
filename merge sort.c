
#include <stdio.h>

void merge(int arr[],int beg,int mid,int end){
    int i,j,k;
    int n1=mid-beg+1; // the size required to store the splitted left sub array
    int n2=end-mid; // the size required to store the splitted right sub array
    
    // copying the splitted array to temporary arrays to merge in sorted order
    int left[n1],right[n2];
    for(int i=0;i<n1;i++)
        left[i]=arr[beg+i];
    for(int j=0;j<n2;j++)
        right[j]=arr[mid+1+j];
        
    // merging the temporary arrays in sorted manner
        
    i=0;j=0;k=beg;
    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k++]=left[i];
        i++;
    }
    while(j<n2){
        arr[k++]=right[j];
        j++;
    }
    
    
}
void merge_sort(int arr[],int beg,int end){
    if(beg<end){
        int mid=(beg+end)/2; // calculating the mid to split
        merge_sort(arr,beg,mid); // splitting the left sub part
        merge_sort(arr,mid+1,end); // splitting the right sub array
        merge(arr,beg,mid,end); // at the end of splitting merging the splitted array
    }
}
void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main()
{
    int arr[]={3,2,5,1,4,0,9,2,4,8};
    int n=10;
    merge_sort(arr,0,n-1);
    print_array(arr,n);

    return 0;
}
