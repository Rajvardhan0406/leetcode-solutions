#include <stdlib.h>

#define MOD 1000000007

int countGoodStrings(int low, int high, int zero, int one) {
    long long* dp = (long long*)malloc((high + 1) * sizeof(long long));
    dp[0] = 1;

    for (int i = 1; i <= high; i++) {
        long long ways = 0;
        if (i - zero >= 0) {
            ways += dp[i - zero];
        }
        if (i - one >= 0) {
            ways += dp[i - one];
        }
        dp[i] = ways % MOD;
    }

    long long answer = 0;
    for (int i = low; i <= high; i++) {
        answer = (answer + dp[i]) % MOD;
    }

    free(dp);
    return (int)answer;
}