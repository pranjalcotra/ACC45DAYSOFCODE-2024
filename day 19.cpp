#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate the next term in the count-and-say sequence
char* getNextTerm(const char* currentTerm) {
    int len = strlen(currentTerm);
    char* nextTerm = (char*)malloc(2 * len + 1); // Allocate space for the next term
    int index = 0;
    
    for (int i = 0; i < len; ) {
        int count = 1;
        
        // Count the number of consecutive characters
        while (i + 1 < len && currentTerm[i] == currentTerm[i + 1]) {
            count++;
            i++;
        }
        
        // Append count and character to the next term
        index += sprintf(nextTerm + index, "%d%c", count, currentTerm[i]);
        i++;
    }
    
    nextTerm[index] = '\0';
    return nextTerm;
}

// Function to generate the n-th term in the count-and-say sequence
char* countAndSay(int n) {
    if (n <= 0) return "";
    
    // Start with the first term "1"
    char* term = (char*)malloc(2);
    strcpy(term, "1");
    
    // Generate terms up to the n-th term
    for (int i = 1; i < n; i++) {
        char* nextTerm = getNextTerm(term);
        free(term); // Free memory for the previous term
        term = nextTerm;
    }
    
    return term;
}

int main() {
    int n;
    printf("Enter the term number: ");
    scanf("%d", &n);
    
    char* result = countAndSay(n);
    printf("The %d-th term in the count-and-say sequence is: %s\n", n, result);
    
    free(result); // Free the memory for the final result
    return 0;
}