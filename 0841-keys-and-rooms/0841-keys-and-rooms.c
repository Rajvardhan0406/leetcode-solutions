bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool* visited = (bool*)calloc(roomsSize, sizeof(bool));
    int* stack = (int*)malloc(roomsSize * sizeof(int));
    int top = 0;
    int visitedCount = 0;
    stack[top++] = 0;
    visited[0] = true;
    visitedCount++;
    while (top > 0) {
        int room = stack[--top];
        for (int j = 0; j < roomsColSize[room]; j++) {
            int key = rooms[room][j];
            if (!visited[key]) {
                visited[key] = true;
                visitedCount++;
                stack[top++] = key;
            }
        }
    }
    free(visited);
    free(stack);
    return visitedCount == roomsSize;
}