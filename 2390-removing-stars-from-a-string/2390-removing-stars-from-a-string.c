#include <stdlib.h>
#include <string.h>
char* removeStars(char* s) {
    int len = strlen(s);
    char* stack = (char*)malloc((len + 1) * sizeof(char));
    int top = -1; 
    for (int i = 0; i < len; i++) {
        if (s[i] == '*') {
            top--; 
        } else {
            stack[++top] = s[i]; 
        }
    }
    stack[top + 1] = '\0'; 
    return stack;
}