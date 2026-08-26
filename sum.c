#include <stdio.h>
#define SIZE 100
int main()
{
    int a[SIZE], hash[SIZE] = {0};
    int n, T, i, x;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter target T: ");
    scanf("%d", &T);
    for(i = 0; i < n; i++)
    {
        x = T - a[i];
        if(x >= 0 && hash[x] == 1)
        {
            printf("Pair found: %d + %d = %d", x, a[i], T);
            return 0;
        }
        hash[a[i]] = 1;
    }
    printf("No pair found");
    return 0;
}
