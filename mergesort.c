#include<stdio.h>
void merge(int a[],int low,int mid,int high){
    int i=low;
    int j=mid+1,k=low;
    int temp[100];
    while(i<=mid&&j<=high){
        if(a[i]<a[j])
        temp[k++]=a[i++];
        else
        temp[k++]=a[j++];
    }
    while(i<=mid)
     temp[k++]=a[i++];
      while(j<=high)
      temp[k++]=a[j++];
      for(i=low;i<=high;i++){
        a[i]=temp[i];
      }
}
void mergesort(int a[],int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
int main(){
    int n,i;int arr[i];
    printf("enter no of elements : ");
    scanf("%d",&n);
    printf("enter the elements :  ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergesort(arr,0,n-1);
    printf("after mergesort :  ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
/*
T(n) = 2*T(n/2) + n -> (1) 
put n = n/2 in (1) 
T(n/2) = 2*T(n/4) + n/2 ->(2) 
  
Substitute (2) in (1) 
T(n) = 2*(2T(n/4) + n/2) + n 
     = 4T(n/4) + n + n 
     = 4T(n/4) + 2n -(3) 
     = 2^2 T(n/2^2) + 2n 
Put n = n/4 in (1) 
T(n/4) = 2T(n/8) + n/4 ->(4) 
Substitute (4) in (3) 

T(n) = 4(2T(n/8) + n/4) + 2n = 8T(n/8) + 3n 
     = 2^3T(n/2^3) + 3n 

T(n) = 2^k T(n/2^k) + k·n 

n = 2^k 
 log n = log 2^k 
 k = log n 
T(n) = n·T(n/n) + log n · n 
     = n·T(1) + n log n 
T(1) = Time required to sort one element 
T(n) = n·T(1) + n log n 

       = O(n log n) 
*/
