#include<stdio.h>
#define size 100
int main(){
        int a [size],hash[size]={0}; int n,i;
    printf("enter no of keys:  ");
    scanf("%d",&n);
    printf("enter the keys: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        hash[a[i]]++;
    }
printf("Frequency:\n");
    for(i = 0; i < size; i++)
    {
        if(hash[i] > 0)
            printf("%d -> %d\n", i, hash[i]);
    }
 
    return 0;
}
