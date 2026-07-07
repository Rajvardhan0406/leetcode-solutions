int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    int* queue = (int*)malloc(m * n * sizeof(int));
    int qFront = 0, qBack = 0;
    int freshCount = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                queue[qBack++] = i * n + j;
            } else if (grid[i][j] == 1) {
                freshCount++;
            }
        }
    }

    if (freshCount == 0) {
        free(queue);
        return 0;
    }

    int minutes = 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (qFront < qBack && freshCount > 0) {
        int levelSize = qBack - qFront;
        minutes++;

        for (int k = 0; k < levelSize; k++) {
            int cell = queue[qFront++];
            int row = cell / n;
            int col = cell % n;

            for (int d = 0; d < 4; d++) {
                int nr = row + dr[d];
                int nc = col + dc[d];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (grid[nr][nc] != 1) continue;

                grid[nr][nc] = 2;
                freshCount--;
                queue[qBack++] = nr * n + nc;
            }
        }
    }

    free(queue);

    return freshCount == 0 ? minutes : -1;
}