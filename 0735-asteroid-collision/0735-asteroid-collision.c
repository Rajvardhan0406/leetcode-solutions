#include <stdlib.h>
#include <stdbool.h>

int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int* stack = (int*)malloc(asteroidsSize * sizeof(int));
    int top = -1; 
    for (int i = 0; i < asteroidsSize; i++) {
        int current = asteroids[i];
        bool alive = true;
        while (alive && top >= 0 && stack[top] > 0 && current < 0) {
            if (stack[top] < -current) {           
                top--;
            } else if (stack[top] == -current) {
                top--;
                alive = false;
            } else {
                alive = false;
            }
        }
        if (alive) {
            stack[++top] = current;
        }
    }
    *returnSize = top + 1;
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        result[i] = stack[i];
    }
    free(stack);
    return result;
}