#include <string.h>
#include <stdlib.h>
int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
char* gcdOfStrings(char* str1, char* str2) {
    int l1 = strlen(str1), l2 = strlen(str2);
    char* concat1 = malloc(l1 + l2 + 1);
    char* concat2 = malloc(l1 + l2 + 1);
    strcpy(concat1, str1); strcat(concat1, str2);
    strcpy(concat2, str2); strcat(concat2, str1);
    if (strcmp(concat1, concat2) != 0) {
        free(concat1); free(concat2);
        return "";
    }
    free(concat1); free(concat2);
    int g = gcd(l1, l2);
    char* res = malloc(g + 1);
    strncpy(res, str1, g);
    res[g] = '\0';
    return res;
}