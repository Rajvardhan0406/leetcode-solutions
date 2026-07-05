/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <string.h>
#include <stdlib.h>

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    int len = strlen(digits);
    if (len == 0) return NULL;

    char* letters[10] = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    int total = 1;
    for (int i = 0; i < len; i++) {
        total *= strlen(letters[digits[i] - '0']);
    }

    char** result = (char**)malloc(total * sizeof(char*));
    for (int i = 0; i < total; i++) {
        result[i] = (char*)malloc((len + 1) * sizeof(char));
    }

    for (int i = 0; i < total; i++) {
        int idx = i;
        for (int d = len - 1; d >= 0; d--) {
            char* letterSet = letters[digits[d] - '0'];
            int numLetters = strlen(letterSet);
            result[i][d] = letterSet[idx % numLetters];
            idx /= numLetters;
        }
        result[i][len] = '\0';
    }

    *returnSize = total;
    return result;
}