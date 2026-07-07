int longestSubarray(int* nums, int numsSize) {
    int left = 0;
    int zeroCount = 0;
    int maxLen = 0;
    for (int right = 0; right < numsSize; right++) {
        if (nums[right] == 0) {
            zeroCount++;
        }
        while (zeroCount > 1) {
            if (nums[left] == 0) {
                zeroCount--;
            }
            left++;
        }
        int windowLen = right - left + 1;
        if (windowLen > maxLen) {
            maxLen = windowLen;
        }
    }
    return maxLen - 1;
}