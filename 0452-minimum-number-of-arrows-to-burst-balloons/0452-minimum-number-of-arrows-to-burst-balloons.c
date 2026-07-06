int cmp(const void* a, const void* b) {
    int* p = *(int**)a;
    int* q = *(int**)b;
    
    if (p[1] < q[1]) return -1;
    if (p[1] > q[1]) return 1;
    return 0;
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
    if (pointsSize == 0) return 0;

    qsort(points, pointsSize, sizeof(int*), cmp);

    int arrows = 1;
    long long arrowPos = points[0][1];  

    for (int i = 1; i < pointsSize; i++) {
        if (points[i][0] > arrowPos) {
            arrows++;
            arrowPos = points[i][1];
        }
    }

    return arrows;
}