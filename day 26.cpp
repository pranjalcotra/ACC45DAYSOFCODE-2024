#include <stdio.h>

int uniquePaths(int m, int n) {
    int dp[m][n];

    // Set the first row and first column to 1 because there's only one way to reach each cell in the first row/column
    for (int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; j++) {
        dp[0][j] = 1;
    }

    // Fill the dp table using the transition relation
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    // The bottom-right corner will contain the total number of unique paths
    return dp[m - 1][n - 1];
}

int main() {
    int m = 3, n = 7;
    int result = uniquePaths(m, n);
    printf("The number of unique paths is: %d\n", result);
    return 0;
}