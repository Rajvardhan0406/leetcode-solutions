#include <string.h>
#include <stdlib.h>

int longestCommonSubsequence(char* text1, char* text2) {
    int m = strlen(text1), n = strlen(text2);

    
    if (n > m) {
        char* tmp = text1; text1 = text2; text2 = tmp;
        int t = m; m = n; n = t;
    }

    int* prev = (int*)calloc(n + 1, sizeof(int));
    int* curr = (int*)calloc(n + 1, sizeof(int));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                curr[j] = prev[j - 1] + 1;
            } else {
                curr[j] = (prev[j] > curr[j - 1]) ? prev[j] : curr[j - 1];
            }
        }
        int* t = prev; prev = curr; curr = t;
    }

    int result = prev[n];
    free(prev);
    free(curr);
    return result;
}