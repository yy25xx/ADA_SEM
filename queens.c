#include <stdio.h>
#include <stdbool.h>

#define MAX 20 // Maximum number of queens

int board[MAX][MAX]; // Chessboard

// Function to print the board
void printSolution(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

// Function to check if a queen can be placed on board[row][col]
bool isSafe(int row, int col, int n) {
    int i, j;

    // Check this row on the left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Recursive function to solve N Queen problem
bool solveNQUtil(int col, int n) {
    // If all queens are placed, then return true
    if (col >= n)
        return true;

    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < n; i++) {
        // Check if the queen can be placed on board[i][col]
        if (isSafe(i, col, n)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQUtil(col + 1, n))
                return true;

            // If placing queen in board[i][col] doesn't lead to a solution,
            // then remove queen from board[i][col] (BACKTRACK)
            board[i][col] = 0;
        }
    }

    // If the queen cannot be placed in any row in this column, then return false
    return false;
}

// Function to solve the N Queen problem
void solveNQ(int n) {
    // Initialize the board to all 0s
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }

    if (solveNQUtil(0, n)) {
        printSolution(n);  // Print the solution
    } else {
        printf("Solution does not exist\n");
    }
}

int main() {
    int n;
    printf("Enter the number of queens: ");
   scanf("%d", &n);
     
    

    solveNQ(n);
    return 0;
}
