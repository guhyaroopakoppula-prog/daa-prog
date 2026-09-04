#include <stdio.h> 
int main() 
{ 

    int a[50], bucket[100] = {0}; 
    int n, i, j; 
    printf("Enter n: "); 

    scanf("%d", &n); 
    printf("Enter elements: "); 

    for(i = 0; i < n; i++)           // O(n) 
    { 

        scanf("%d", &a[i]); 
        bucket[a[i]]++; 
    } 
    printf("Sorted array: "); 
    for(i = 0; i < 100; i++)           //  runs k times 

    { 
        for(j = 0; j < bucket[i]; j++)   //runs n times 

            printf("%d ", i); 
    } 
    return 0; 

} 
/*
Time Complexity : 

     T(n)=O(n)+O(k+n) 

     T(n)=O(n+k) 
*/
