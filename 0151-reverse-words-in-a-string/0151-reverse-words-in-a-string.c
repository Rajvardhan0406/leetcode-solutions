char* reverseWords(char* s) {
    int len = strlen(s);
    char* result = malloc(len + 1);
    int write = 0;   
    int i = len - 1;  
    while (i >= 0) {
        while (i >= 0 && s[i] == ' ') i--;
        if (i < 0) break;
        int wordEnd = i;
        while (i >= 0 && s[i] != ' ') i--;
        int wordStart = i + 1;
        if (write > 0) result[write++] = ' ';
        for (int j = wordStart; j <= wordEnd; j++) {
            result[write++] = s[j];
        }
    }
    result[write] = '\0';
    return result;
}