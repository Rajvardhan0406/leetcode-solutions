int rob(int* nums, int numsSize) {
    int prev2 = 0, prev1 = 0;  
    for (int i = 0; i < numsSize; i++) {
        int take = prev2 + nums[i];  
        int skip = prev1;            
        int cur = take > skip ? take : skip;
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}