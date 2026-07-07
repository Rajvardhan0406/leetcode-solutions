int minCostClimbingStairs(int* cost, int costSize) {
    int prev2 = 0, prev1 = 0;  
    for (int i = 2; i <= costSize; i++) {
        int step1 = prev1 + cost[i - 1];  
        int step2 = prev2 + cost[i - 2];  
        int cur = step1 < step2 ? step1 : step2;
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}