/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes) {
    #define OFFSET 1000
    #define RANGE 2001 

    bool inNums1[2001] = {false};
    bool inNums2[2001] = {false};

    for (int i = 0; i < nums1Size; i++) {
        inNums1[nums1[i] + OFFSET] = true;
    }
    for (int i = 0; i < nums2Size; i++) {
        inNums2[nums2[i] + OFFSET] = true;
    }

    int** result = (int**)malloc(2 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    
    int count1 = 0, count2 = 0;
    for (int v = 0; v < RANGE; v++) {
        if (inNums1[v] && !inNums2[v]) count1++;
        if (inNums2[v] && !inNums1[v]) count2++;
    }

    result[0] = (int*)malloc(count1 * sizeof(int));
    result[1] = (int*)malloc(count2 * sizeof(int));

   
    int idx1 = 0, idx2 = 0;
    for (int v = 0; v < RANGE; v++) {
        if (inNums1[v] && !inNums2[v]) {
            result[0][idx1++] = v - OFFSET;
        }
        if (inNums2[v] && !inNums1[v]) {
            result[1][idx2++] = v - OFFSET;
        }
    }

    (*returnColumnSizes)[0] = count1;
    (*returnColumnSizes)[1] = count2;

    return result;
}