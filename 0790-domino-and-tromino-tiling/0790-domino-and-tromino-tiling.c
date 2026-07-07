#define MOD 1000000007LL

int numTilings(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    long long f0 = 1, f1 = 1, f2 = 2; 
    long long f3 = 0;
    for (int i = 3; i <= n; i++) {
        f3 = (2 * f2 % MOD + f0) % MOD;
        f0 = f1;
        f1 = f2;
        f2 = f3;
    }
    return (int)f2;
}