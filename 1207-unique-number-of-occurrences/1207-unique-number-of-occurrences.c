bool uniqueOccurrences(int* arr, int arrSize) {
    int OFFSET = 1000;
    int VALUE_RANGE = 2001;   
    int freq[2001] = {0};
    for (int i = 0; i < arrSize; i++) {
        freq[arr[i] + OFFSET]++;
    }
    int countOfCounts[1001] = {0};
    for (int v = 0; v < VALUE_RANGE; v++) {
        if (freq[v] > 0) {
            countOfCounts[freq[v]]++;
            if (countOfCounts[freq[v]] > 1) {
                return false; 
            }
        }
    }
    return true;
}