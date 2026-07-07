bool canEat(int* piles, int pilesSize, int h, int k) {
    long long hours = 0;

    for (int i = 0; i < pilesSize; i++) {
        hours += (piles[i] + k - 1) / k;
    }
    return hours <= h;
}
int minEatingSpeed(int* piles, int pilesSize, int h) {
    int lo = 1, hi = 1;
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > hi) hi = piles[i];
    }
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (canEat(piles, pilesSize, h, mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}