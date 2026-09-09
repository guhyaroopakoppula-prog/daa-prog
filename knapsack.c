#include <stdio.h> 

struct Item { 

    int weight, value; 

}; 

int main() { 

    struct Item a[] = {{10, 60}, {20, 100}, {30, 120}}; 

    int n = 3, capacity = 50; 

    float profit = 0; 

    for (int i = 0; i < n - 1; i++) 

        for (int j = i + 1; j < n; j++) 

            if ((float)a[i].value/a[i].weight < 

                (float)a[j].value/a[j].weight) { 

                struct Item t = a[i]; 

                a[i] = a[j]; 

                a[j] = t; 

            } 

    for (int i = 0; i < n; i++) { 

        if (capacity >= a[i].weight) { 

            capacity -= a[i].weight; 

            profit += a[i].value; 

        } else { 

            profit += (float)a[i].value / a[i].weight * capacity; 

            break; 

        } 

    } 

  

    printf("Maximum Profit = %.2f", profit); 

    return 0; 

}