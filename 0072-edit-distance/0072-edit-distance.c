int minDistance(char* word1, char* word2) {
    int n = strlen(word1), m = strlen(word2);
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++) dp[i][0] = i;   
    for (int j = 0; j <= m; j++) dp[0][j] = j;   

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                int rep = dp[i - 1][j - 1];
                int del = dp[i - 1][j];
                int ins = dp[i][j - 1];
                int mn = rep < del ? rep : del;
                mn = mn < ins ? mn : ins;
                dp[i][j] = 1 + mn;
            }
        }
    }

    return dp[n][m];
}