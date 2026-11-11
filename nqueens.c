#include <stdio.h> 

#include <stdlib.h> 

  

int board[20][20], n; 

  

void printSolution() 

{ 

    int i, j; 

  

    printf("\nSolution:\n"); 

    for (i = 0; i < n; i++) 

    { 

        for (j = 0; j < n; j++) 

        { 

            printf("%d ", board[i][j]); 

        } 

        printf("\n"); 

    } 

} 

  

int isSafe(int row, int col) 

{ 

    int i, j; 

 

    for (i = 0; i < row; i++) 

        if (board[i][col]) 

            return 0; 

 

    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) 

        if (board[i][j]) 

            return 0; 

    for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) 

        if (board[i][j]) 

            return 0; 

  

    return 1; 

} 

  

int solveNQueen(int row) 

{ 

    int col; 

  

    if (row == n) 

    { 

        printSolution(); 

        return 1; 

    } 

  

    for (col = 0; col < n; col++) 

    { 

        if (isSafe(row, col)) 

        { 

            board[row][col] = 1; 

  

            if (solveNQueen(row + 1)) 

                return 1; 

 

            board[row][col] = 0; 

        } 

    } 

  

    return 0; 

} 

  

int main() 

{ 

    int i, j; 

  

    printf("Enter the value of N: "); 

    scanf("%d", &n); 

  

    if (n < 1 || n > 20) 

    { 

        printf("Enter N between 1 and 20.\n"); 

        return 0; 

    } 

  

    for (i = 0; i < n; i++) 

        for (j = 0; j < n; j++) 

            board[i][j] = 0; 

  

    if (!solveNQueen(0)) 

        printf("Solution does not exist.\n"); 

  

    return 0; 

} 
