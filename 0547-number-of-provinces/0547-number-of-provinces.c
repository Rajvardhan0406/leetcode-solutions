int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int n = isConnectedSize;
    int visited[200] = {0};
    int stack[200], top;
    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        provinces++;
        top = 0;
        stack[top++] = i;
        visited[i] = 1;

        while (top > 0) {
            int cur = stack[--top];
            for (int j = 0; j < n; j++) {
                if (isConnected[cur][j] == 1 && !visited[j]) {
                    visited[j] = 1;
                    stack[top++] = j;
                }
            }
        }
    }

    return provinces;
}