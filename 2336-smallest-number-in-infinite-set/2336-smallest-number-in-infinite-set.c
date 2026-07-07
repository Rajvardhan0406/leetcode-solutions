#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int curr;
    bool added[1001];
} SmallestInfiniteSet;

SmallestInfiniteSet* smallestInfiniteSetCreate() {
    SmallestInfiniteSet* obj = (SmallestInfiniteSet*)malloc(sizeof(SmallestInfiniteSet));
    obj->curr = 1;
    for (int i = 0; i <= 1000; i++) {
        obj->added[i] = false;
    }
    return obj;
}

int smallestInfiniteSetPopSmallest(SmallestInfiniteSet* obj) {
    for (int i = 1; i < obj->curr; i++) {
        if (obj->added[i]) {
            obj->added[i] = false;
            return i;
        }
    }
    return (obj->curr)++;
}

void smallestInfiniteSetAddBack(SmallestInfiniteSet* obj, int num) {
    if (num < obj->curr) {
        obj->added[num] = true;
    }
}

void smallestInfiniteSetFree(SmallestInfiniteSet* obj) {
    free(obj);
}