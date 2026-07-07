void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void siftDown(int* heap, int size, int i) {
    while (1) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < size && heap[left] > heap[largest]) largest = left;
        if (right < size && heap[right] > heap[largest]) largest = right;
        if (largest == i) break;
        swap(&heap[i], &heap[largest]);
        i = largest;
    }
}
void siftUp(int* heap, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] >= heap[i]) break;
        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}
int minStoneSum(int* piles, int pilesSize, int k) {
    int* heap = (int*)malloc(pilesSize * sizeof(int));
    memcpy(heap, piles, pilesSize * sizeof(int));
    for (int i = pilesSize / 2 - 1; i >= 0; i--) {
        siftDown(heap, pilesSize, i);
    }
    for (int op = 0; op < k; op++) {
        int half = heap[0] / 2; 
        heap[0] = heap[0] - half; 
        siftDown(heap, pilesSize, 0);
    }
    long long total = 0;
    for (int i = 0; i < pilesSize; i++) {
        total += heap[i];
    }
    free(heap);
    return (int)total;
}