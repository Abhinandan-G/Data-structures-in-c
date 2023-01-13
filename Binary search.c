#include<stdio.h>
int main(){
	printf("Enter the size of the array\n");
	int n;
	scanf("%d",&n);
	int a[n],temp,low=0,high=n-1,mid,element,flag=0;
	printf("Enter the elements of the array\n");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n-1;i++){   //Binary search only works for sorted elements so we sort it first.
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		}
	}
	printf("Enter the element you need to search\n");
	scanf("%d",&element);
	while(low<=high){
		mid=(low+high)/2;
		if(a[mid]==element){
			flag=1;
			break;
		}
		else if(element>mid)
			low=mid+1;
		else if(element<mid)
			high=mid-1;
	}
	if(flag==0)
		printf("Element not found\n");
	else if(flag==1)
		printf("Element found\n");
	return 0;
}