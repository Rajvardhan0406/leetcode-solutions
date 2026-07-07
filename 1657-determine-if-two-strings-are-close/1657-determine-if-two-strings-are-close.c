#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
bool closeStrings(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    if (len1 != len2) return false;

    int freq1[26] = {0};
    int freq2[26] = {0};
    for (int i = 0; i < len1; i++) {
        freq1[word1[i] - 'a']++;
    }
    for (int i = 0; i < len2; i++) {
        freq2[word2[i] - 'a']++;
    }
    for (int c = 0; c < 26; c++) {
        if ((freq1[c] == 0) != (freq2[c] == 0)) {
            return false;
        }
    }
    qsort(freq1, 26, sizeof(int), compare);
    qsort(freq2, 26, sizeof(int), compare);

    for (int c = 0; c < 26; c++) {
        if (freq1[c] != freq2[c]) {
            return false;
        }
    }

    return true;
}