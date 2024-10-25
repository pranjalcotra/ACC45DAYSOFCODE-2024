#include <stdio.h>
#include <stdlib.h>

// Structure to store a combination
typedef struct {
    int *combination;
    int size;
} Combination;

// Result structure to store all unique combinations
typedef struct {
    Combination *combinations;
    int count;
} Result;

// Function to add a new combination to the result set
void addCombination(Result *result, int *current, int currentSize) {
    Combination newCombination;
    newCombination.size = currentSize;
    newCombination.combination = (int *)malloc(currentSize * sizeof(int));
    for (int i = 0; i < currentSize; i++) {
        newCombination.combination[i] = current[i];
    }

    result->combinations[result->count++] = newCombination;
}

// Recursive backtracking function
void backtrack(int *candidates, int candidatesSize, int target, int *current, int currentSize, int start, Result *result) {
    if (target == 0) {
        addCombination(result, current, currentSize);
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        if (candidates[i] > target) {
            continue;
        }

        // Choose the candidate
        current[currentSize] = candidates[i];
        // Recursive call with the current candidate
        backtrack(candidates, candidatesSize, target - candidates[i], current, currentSize + 1, i, result);
    }
}

// Function to find all unique combinations
Result combinationSum(int *candidates, int candidatesSize, int target) {
    Result result;
    result.combinations = (Combination *)malloc(150 * sizeof(Combination));
    result.count = 0;

    int *current = (int *)malloc(target * sizeof(int));
    backtrack(candidates, candidatesSize, target, current, 0, 0, &result);

    free(current);
    return result;
}

// Function to free memory allocated for the result
void freeResult(Result *result) {
    for (int i = 0; i < result->count; i++) {
        free(result->combinations[i].combination);
    }
    free(result->combinations);
}

// Main function
int main() {
    int candidates[] = {2, 3, 6, 7};
    int target = 7;
    int candidatesSize = sizeof(candidates) / sizeof(candidates[0]);

    Result result = combinationSum(candidates, candidatesSize, target);

    printf("Unique combinations that sum to %d are:\n", target);
    for (int i = 0; i < result.count; i++) {
        printf("[ ");
        for (int j = 0; j < result.combinations[i].size; j++) {
            printf("%d ", result.combinations[i].combination[j]);
        }
        printf("]\n");
    }

    freeResult(&result);
    return 0;
}