#include <stdio.h>
#include <limits.h>

int minPathSum(int** grid, int m, int n) {
    // Initialize a 2D array dp with the same dimensions as grid
    int dp[m][n];
    
    // Set the starting point
    dp[0][0] = grid[0][0];
    
    // Fill the first row (can only come from the left)
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // Fill the first column (can only come from above)
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // Fill the rest of the dp table
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = grid[i][j] + (dp[i - 1][j] < dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1]);
        }
    }

    // The bottom-right cell contains the minimum path sum
    return dp[m - 1][n - 1];
}

int main() {
    int m = 3, n = 3;
    int grid[3][3] = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    // Convert 2D array to array of pointers for function compatibility
    int* gridPtrs[m];
    for (int i = 0; i < m; i++) {
        gridPtrs[i] = grid[i];
    }

    int result = minPathSum(gridPtrs, m, n);
    printf("The minimum path sum is: %d\n", result);

    return 0;
}