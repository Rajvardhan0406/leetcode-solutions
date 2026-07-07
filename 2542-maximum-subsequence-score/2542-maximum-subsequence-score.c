#include <stdlib.h>

typedef struct {
    int nums1;
    int nums2;
} Pair;

int cmpDesc(const void* a, const void* b) {
    Pair* p = (Pair*)a;
    Pair* q = (Pair*)b;

    if (p->nums2 < q->nums2) return 1;
    if (p->nums2 > q->nums2) return -1;
    return 0;
}

void heapPush(int* heap, int* size, int val) {
    int i = (*size)++;
    heap[i] = val;

    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] <= heap[i]) break;

        int temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;

        i = parent;
    }
}

int heapPop(int* heap, int* size) {
    int top = heap[0];

    heap[0] = heap[--(*size)];

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < *size && heap[left] < heap[smallest])
            smallest = left;

        if (right < *size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i)
            break;

        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        i = smallest;
    }

    return top;
}

long long maxScore(int* nums1, int nums1Size, int* nums2, int nums2Size, int k) {

    int n = nums1Size;

    Pair* pairs = (Pair*)malloc(n * sizeof(Pair));

    for (int i = 0; i < n; i++) {
        pairs[i].nums1 = nums1[i];
        pairs[i].nums2 = nums2[i];
    }

    qsort(pairs, n, sizeof(Pair), cmpDesc);

    // Allocate k+1 because we temporarily insert one extra element
    int* heap = (int*)malloc((k + 1) * sizeof(int));
    int heapSize = 0;

    long long sum = 0;
    long long best = 0;

    for (int i = 0; i < n; i++) {

        heapPush(heap, &heapSize, pairs[i].nums1);
        sum += pairs[i].nums1;

        if (heapSize > k) {
            sum -= heapPop(heap, &heapSize);
        }

        if (heapSize == k) {
            long long score = sum * (long long)pairs[i].nums2;
            if (score > best)
                best = score;
        }
    }

    free(heap);
    free(pairs);

    return best;
}