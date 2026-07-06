int singleNumber(int* nums, int numsSize) {
    unsigned int result = 0;

    for (int bit = 0; bit < 32; bit++) {
        int sum = 0;
        for (int i = 0; i < numsSize; i++) {
            sum += ((unsigned int)nums[i] >> bit) & 1;
        }
        if (sum % 3 != 0) {
            result |= (1u << bit);   
        }
    }

    return (int)result;   
}