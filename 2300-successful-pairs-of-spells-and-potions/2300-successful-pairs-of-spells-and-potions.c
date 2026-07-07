/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmpInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {
    
    int* sortedPotions = (int*)malloc(potionsSize * sizeof(int));
    memcpy(sortedPotions, potions, potionsSize * sizeof(int));
    qsort(sortedPotions, potionsSize, sizeof(int), cmpInt);

    int* result = (int*)malloc(spellsSize * sizeof(int));

    for (int i = 0; i < spellsSize; i++) {
        long long s = spells[i];
        int lo = 0, hi = potionsSize; 

        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (s * (long long)sortedPotions[mid] >= success) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        result[i] = potionsSize - lo; 
    }

    free(sortedPotions);
    *returnSize = spellsSize;
    return result;
}