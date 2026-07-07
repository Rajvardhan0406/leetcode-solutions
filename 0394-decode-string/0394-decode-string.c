#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* decodeString(char* s) {
    int n = strlen(s);
    int maxLen = 100001;         
    int countStack[30];
    int countTop = -1;
    char* strStack[30];
    int strTop = -1;
    char* curStr = (char*)malloc(maxLen * sizeof(char));
    curStr[0] = '\0';
    int curLen = 0;
    int i = 0;
    while (i < n) {
        if (isdigit(s[i])) {
            int num = 0;
            while (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            countStack[++countTop] = num;
        } else if (s[i] == '[') {
            strStack[++strTop] = curStr;
            curStr = (char*)malloc(maxLen * sizeof(char));
            curStr[0] = '\0';
            curLen = 0;
            i++;
        } else if (s[i] == ']') {
            int repeatCount = countStack[countTop--];
            char* prevStr = strStack[strTop--];
            int prevLen = strlen(prevStr);
            int segLen = curLen;
            for (int k = 0; k < repeatCount; k++) {
                strcpy(prevStr + prevLen, curStr);
                prevLen += segLen;
            }
            prevStr[prevLen] = '\0';
            free(curStr);
            curStr = prevStr;
            curLen = prevLen;
            i++;
        } else {
            curStr[curLen++] = s[i];
            curStr[curLen] = '\0';
            i++;
        }
    }
    return curStr;
}