/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

#define MAX_COMBOS 128  

void backtrack(int start, int k, int remaining, int* path, int pathLen,
                int** result, int* returnColumnSizes, int* count) {
    if (pathLen == k) {
        if (remaining == 0) {
            int* combo = (int*)malloc(k * sizeof(int));
            for (int i = 0; i < k; i++) combo[i] = path[i];
            result[*count] = combo;
            returnColumnSizes[*count] = k;
            (*count)++;
        }
        return;
    }

    
    for (int num = start; num <= 9; num++) {
        if (num > remaining) break;             
        
        int slotsLeft = k - pathLen - 1;
        int minPossible = num + (slotsLeft * (2 * num + slotsLeft + 1)) / 2; 
        
        
        path[pathLen] = num;
        backtrack(num + 1, k, remaining - num, path, pathLen + 1, result, returnColumnSizes, count);
    }
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(MAX_COMBOS * sizeof(int*));
    *returnColumnSizes = (int*)malloc(MAX_COMBOS * sizeof(int));
    int path[9];
    int count = 0;

    backtrack(1, k, n, path, 0, result, *returnColumnSizes, &count);

    *returnSize = count;
    return result;
}