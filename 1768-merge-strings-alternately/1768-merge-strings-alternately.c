char* mergeAlternately(char* word1, char* word2) {
    int l1 = strlen(word1), l2 = strlen(word2);
    char* res = malloc(l1 + l2 + 1);
    int i = 0, j = 0, k = 0;

    while (i < l1 || j < l2) {
        if (i < l1) res[k++] = word1[i++];
        if (j < l2) res[k++] = word2[j++];
    }

    res[k] = '\0';
    return res;
}