bool check(int* nums, int numsSize) {
    int count = 0;
    int i;
    for(i = 0; i < numsSize; i++) {
        if(nums[i] > nums[(i + 1) % numsSize]) {
            count++;
        }
    }
    return count <= 1;
}