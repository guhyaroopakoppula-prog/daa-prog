#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    int j;

    for(j = low; j < high; j++)
    {
        if(a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[high]);

    return i + 1;
}

void quicksort(int a[], int low, int high)
{
    if(low < high)
    {
        int p = partition(a, low, high);

        quicksort(a, low, p - 1);
        quicksort(a, p + 1, high);
    }
}

int main()
{
    int a[50], n, i;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quicksort(a, 0, n - 1);

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
/*
Time Complexity : 

T(n) = 2T(n/2) + n ->1 

Put n = n/2 in 1 

T(n/2) = 2T(n/4) + n/2 ->2 

Substitute 2 in 1 

T(n) = 2(2T(n/4) + n/2) + n 

     = 4T(n/4) + n + n 

     = 4T(n/4) + 2n ->3 

Put n = n/4 in 1 

T(n/4) = 2T(n/8) + n/4 ->4 

Substitute 4 in 3 

T(n) = 4(2T(n/8) + n/4) + 2n 

     = 8T(n/8) + n + 2n 

     = 8T(n/8) + 3n ->5 
  T(n) = 2^k T(n/2^k) + k·n 

Put n/2^k = 1  
  n = 2^k  
 k = log n 

T(n) = 2^(log n) T(1) + n log n 

     = n·T(1) + n log n 

  

T(1) = Time required to sort one element 

∴ T(n) = n·T(1) + n log n 

       = O(n log n)
*/
