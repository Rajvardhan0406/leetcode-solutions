/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxAns = 0;

void dfs(struct TreeNode* node, int leftLen, int rightLen) {
    if (node == NULL) {
        return;
    }

    if (leftLen > maxAns) maxAns = leftLen;
    if (rightLen > maxAns) maxAns = rightLen;

    dfs(node->left, rightLen + 1, 0);
    dfs(node->right, 0, leftLen + 1);
}

int longestZigZag(struct TreeNode* root) {
    maxAns = 0;
    dfs(root, 0, 0);
    return maxAns;
}