/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int dfs(TreeNode* root, int& sum, int& num) {
        if (root == nullptr) {
            sum = num = 0;
            return 0;
        }
        int r = dfs(root->left, sum, num), s = sum + root->val, n = num + 1;
        r += dfs(root->right, sum, num);
        sum += s;
        num += n;
        if (sum / num == root->val) {
            ++r;
        }
        return r;
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int s = 0, n = 0;
        return dfs(root, s, n);
    }
};