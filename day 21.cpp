#include <stdio.h>
#include <stdlib.h>

void generateParenthesisHelper(int n, int open, int close, char* str, int pos) {
    if (close == n) {
        // When we've used all closing brackets, we have a valid combination
        printf("%s\n", str);
        return;
    }

    // If we have remaining open parentheses, add one and recurse
    if (open < n) {
        str[pos] = '(';
        generateParenthesisHelper(n, open + 1, close, str, pos + 1);
    }

    // If we have more open parentheses used, we can add a closing parenthesis
    if (close < open) {
        str[pos] = ')';
        generateParenthesisHelper(n, open, close + 1, str, pos + 1);
    }
}

void generateParenthesis(int n) {
    // Create a string to store a single combination, length is 2*n + 1 for null terminator
    char *str = (char *)malloc(2 * n + 1);
    str[2 * n] = '\0';  // Null terminate the string

    // Start the recursive helper function
    generateParenthesisHelper(n, 0, 0, str, 0);

    // Free the memory allocated for the string
    free(str);
}

int main() {
    int n;
    printf("Enter the number of pairs of parentheses: ");
    scanf("%d", &n);

    generateParenthesis(n);

    return 0;
}