#include <stdio.h> 

struct Result { 

    int max; 

    int min; 

}; 

struct Result findMaxMin(int a[], int low, int high) { 

    struct Result r, left, right; 

    if (low == high) { 

        r.max = a[low]; 

        r.min = a[low]; 

        return r; 

    } 

    if (high == low + 1) { 

        if (a[low] > a[high]) { 

            r.max = a[low]; 

            r.min = a[high]; 

        } else { 

            r.max = a[high]; 

            r.min = a[low]; 

        } 

        return r; 

    } 

    int mid = (low + high) / 2; 

     left = findMaxMin(a, low, mid); 

    right = findMaxMin(a, mid + 1, high); 

    r.max = (left.max > right.max) ? left.max : right.max; 

    r.min = (left.min < right.min) ? left.min : right.min; 

    return r; 

}  

int main() { 

    int a[] = {10, 5, 25, 8, 15, 2, 30}; 

    int n = sizeof(a) / sizeof(a[0]); 

    struct Result result = findMaxMin(a, 0, n - 1); 

    printf("Maximum element = %d\n", result.max); 

    printf("Minimum element = %d\n", result.min); 

    return 0; 

} 