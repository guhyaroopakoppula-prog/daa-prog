#include <stdio.h> 

int max(int a, int b) { 

    return a > b ? a : b; 

} 

int maxSub(int a[], int l, int r) { 

    if (l == r) 

        return a[l]; 

  

    int m = (l + r) / 2; 

    int left = maxSub(a, l, m); 

    int right = maxSub(a, m + 1, r); 

    int sum = 0, leftSum = -9999, rightSum = -9999; 

    for (int i = m; i >= l; i--) { 

        sum += a[i]; 

        leftSum = max(leftSum, sum); 

    } 

    sum = 0; 

    for (int i = m + 1; i <= r; i++) { 

        sum += a[i]; 

        rightSum = max(rightSum, sum); 

    } 

    return max(max(left, right), leftSum + rightSum); 

} 

int main() { 

    int a[] = {-2, 3, -1, 5, -6, 2}; 

    int n = 6; 

    printf("Maximum Subarray Sum = %d", maxSub(a, 0, n - 1)); 

    return 0; 

} 