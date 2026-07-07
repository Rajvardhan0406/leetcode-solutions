int isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int maxVowels(char* s, int k) {
    int count = 0;
    int n = strlen(s);
    for (int i = 0; i < k; i++) {
        count += isVowel(s[i]);
    }
    int maxCount = count;
    for (int i = k; i < n; i++) {
        count += isVowel(s[i]) - isVowel(s[i - k]);
        if (count > maxCount) {
            maxCount = count;
        }
    }
    return maxCount;
}