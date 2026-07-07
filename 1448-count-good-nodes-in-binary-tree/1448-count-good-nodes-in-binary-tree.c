/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode* node, int maxSoFar, int* count) {
    if (node == NULL) {
        return;
    }
    if (node->val >= maxSoFar) {
        (*count)++;
        maxSoFar = node->val;
    }
    dfs(node->left, maxSoFar, count);
    dfs(node->right, maxSoFar, count);
}
int goodNodes(struct TreeNode* root) {
    int count = 0;
    dfs(root, root->val, &count);   
    return count;
}