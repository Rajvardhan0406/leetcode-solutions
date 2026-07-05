/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>

#define MAXN 45

double* calcEquation(char*** equations, int equationsSize, int* equationsColSize,
                      double* values, int valuesSize,
                      char*** queries, int queriesSize, int* queriesColSize,
                      int* returnSize) {
    char nodes[MAXN][6];
    int n = 0, adjCount[MAXN] = {0};
    int adjTo[MAXN][MAXN];
    double adjW[MAXN][MAXN];

    for (int i = 0; i < equationsSize; i++) {
        int a = -1, b = -1;
        for (int j = 0; j < n; j++) {
            if (strcmp(nodes[j], equations[i][0]) == 0) a = j;
            if (strcmp(nodes[j], equations[i][1]) == 0) b = j;
        }
        if (a == -1) { strcpy(nodes[n], equations[i][0]); a = n++; }
        if (b == -1) { strcpy(nodes[n], equations[i][1]); b = n++; }

        adjTo[a][adjCount[a]] = b; adjW[a][adjCount[a]++] = values[i];
        adjTo[b][adjCount[b]] = a; adjW[b][adjCount[b]++] = 1.0 / values[i];
    }

    double* res = (double*)malloc(queriesSize * sizeof(double));

    for (int q = 0; q < queriesSize; q++) {
        int src = -1, dst = -1;
        for (int j = 0; j < n; j++) {
            if (strcmp(nodes[j], queries[q][0]) == 0) src = j;
            if (strcmp(nodes[j], queries[q][1]) == 0) dst = j;
        }
        if (src == -1 || dst == -1) { res[q] = -1.0; continue; }
        if (src == dst) { res[q] = 1.0; continue; }

        int visited[MAXN] = {0}, queue[MAXN], front = 0, back = 0;
        double acc[MAXN];
        queue[back++] = src; visited[src] = 1; acc[src] = 1.0;
        double found = -1.0;

        while (front < back) {
            int cur = queue[front++];
            if (cur == dst) { found = acc[cur]; break; }
            for (int k = 0; k < adjCount[cur]; k++) {
                int nxt = adjTo[cur][k];
                if (!visited[nxt]) {
                    visited[nxt] = 1;
                    acc[nxt] = acc[cur] * adjW[cur][k];
                    queue[back++] = nxt;
                }
            }
        }
        res[q] = found;
    }

    *returnSize = queriesSize;
    return res;
}