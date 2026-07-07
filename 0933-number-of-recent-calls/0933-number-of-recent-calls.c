typedef struct {
    int* requests;
    int size;     
    int front;     
    int back;      
    int capacity;
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter* counter = (RecentCounter*)malloc(sizeof(RecentCounter));
    counter->capacity = 10000; 
    counter->requests = (int*)malloc(counter->capacity * sizeof(int));
    counter->front = 0;
    counter->back = 0;
    return counter;
}

int recentCounterPing(RecentCounter* obj, int t) {
    obj->requests[obj->back++] = t;

    while (obj->requests[obj->front] < t - 3000) {
        obj->front++;
    }

    return obj->back - obj->front;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj->requests);
    free(obj);
}