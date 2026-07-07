/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX_NODES 1001

typedef struct {
    long sum[MAX_NODES];
    int freq[MAX_NODES];
    int size;
} PrefixMap;

void mapAdd(PrefixMap* map, long sum) {
    for (int i = 0; i < map->size; i++) {
        if (map->sum[i] == sum) {
            map->freq[i]++;
            return;
        }
    }
    map->sum[map->size] = sum;
    map->freq[map->size] = 1;
    map->size++;
}

void mapRemove(PrefixMap* map, long sum) {
    for (int i = 0; i < map->size; i++) {
        if (map->sum[i] == sum) {
            map->freq[i]--;
            return;
        }
    }
}

int mapGet(PrefixMap* map, long sum) {
    for (int i = 0; i < map->size; i++) {
        if (map->sum[i] == sum) {
            return map->freq[i];
        }
    }
    return 0;
}

void dfs(struct TreeNode* node, long currentSum, int targetSum, PrefixMap* map, int* count) {
    if (node == NULL) {
        return;
    }

    currentSum += node->val;

    *count += mapGet(map, currentSum - targetSum);

    mapAdd(map, currentSum);

    dfs(node->left, currentSum, targetSum, map, count);
    dfs(node->right, currentSum, targetSum, map, count);

    mapRemove(map, currentSum);
}

int pathSum(struct TreeNode* root, int targetSum) {
    PrefixMap map;
    map.size = 0;

    int count = 0;

    mapAdd(&map, 0); 
    dfs(root, 0, targetSum, &map, &count);

    return count;
}