int minReorder(int n, int** connections, int connectionsSize, int* connectionsColSize) {
    int edgeCount = 2 * connectionsSize;
    int* head = (int*)malloc(n * sizeof(int));
    int* nxt  = (int*)malloc(edgeCount * sizeof(int));
    int* to   = (int*)malloc(edgeCount * sizeof(int));
    int* w    = (int*)malloc(edgeCount * sizeof(int));
    for (int i = 0; i < n; i++) head[i] = -1;

    
    int idx = 0;
    for (int i = 0; i < connectionsSize; i++) {
        int a = connections[i][0];
        int b = connections[i][1];
        to[idx] = b; w[idx] = 1; nxt[idx] = head[a]; head[a] = idx++;
        to[idx] = a; w[idx] = 0; nxt[idx] = head[b]; head[b] = idx++;
    }

    int* visited = (int*)calloc(n, sizeof(int));
    int* queue   = (int*)malloc(n * sizeof(int));
    int qHead = 0, qTail = 0;

    queue[qTail++] = 0;
    visited[0] = 1;
    int count = 0;

    while (qHead < qTail) {
        int u = queue[qHead++];
        for (int e = head[u]; e != -1; e = nxt[e]) {
            int v = to[e];
            if (!visited[v]) {
                visited[v] = 1;
                count += w[e];     
                queue[qTail++] = v;
            }
        }
    }

    free(head); free(nxt); free(to); free(w); free(visited); free(queue);
    return count;
}