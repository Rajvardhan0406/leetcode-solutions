int cmp(const void* a, const void* b) {
    int* p = *(int**)a;
    int* q = *(int**)b;
    return p[1] - q[1];  
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize == 0) return 0;

    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    int count = 0;         
    int prevEnd = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] < prevEnd) {
            count++;
        } else {
            
            prevEnd = intervals[i][1];
        }
    }

    return count;
}