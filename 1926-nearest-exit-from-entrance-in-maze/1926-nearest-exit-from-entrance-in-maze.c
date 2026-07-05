int nearestExit(char** maze, int mazeSize, int* mazeColSize, int* entrance, int entranceSize) {
    int m = mazeSize;
    int n = mazeColSize[0];

    bool** visited = (bool**)malloc(m * sizeof(bool*));
    for (int i = 0; i < m; i++) {
        visited[i] = (bool*)calloc(n, sizeof(bool));
    }

    
    int* queue = (int*)malloc(m * n * sizeof(int));
    int qFront = 0, qBack = 0;

    int startRow = entrance[0], startCol = entrance[1];
    queue[qBack++] = startRow * n + startCol;
    visited[startRow][startCol] = true;

    int steps = 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (qFront < qBack) {
        int levelSize = qBack - qFront;
        steps++;

        for (int k = 0; k < levelSize; k++) {
            int cell = queue[qFront++];
            int row = cell / n;
            int col = cell % n;

            for (int d = 0; d < 4; d++) {
                int nr = row + dr[d];
                int nc = col + dc[d];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (visited[nr][nc]) continue;
                if (maze[nr][nc] == '+') continue;

                
                if (nr == 0 || nr == m - 1 || nc == 0 || nc == n - 1) {
                    for (int i = 0; i < m; i++) free(visited[i]);
                    free(visited);
                    free(queue);
                    return steps;
                }

                visited[nr][nc] = true;
                queue[qBack++] = nr * n + nc;
            }
        }
    }

    for (int i = 0; i < m; i++) free(visited[i]);
    free(visited);
    free(queue);

    return -1;
}