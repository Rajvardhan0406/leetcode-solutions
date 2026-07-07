/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void collectLeaves(struct TreeNode* node, int* leaves, int* count) {
    if (node == NULL) {
        return;
    }
    if (node->left == NULL && node->right == NULL) {
        leaves[*count] = node->val;
        (*count)++;
        return;
    }
    collectLeaves(node->left, leaves, count);
    collectLeaves(node->right, leaves, count);
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int leaves1[200], leaves2[200];
    int count1 = 0, count2 = 0;

    collectLeaves(root1, leaves1, &count1);
    collectLeaves(root2, leaves2, &count2);

    if (count1 != count2) {
        return false;
    }

    for (int i = 0; i < count1; i++) {
        if (leaves1[i] != leaves2[i]) {
            return false;
        }
    }

    return true;
}