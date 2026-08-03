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
public:

    bool ans = true;

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;

        height(root);
        return ans;
    }

    int height(TreeNode* root){
        if(root == nullptr) return 0;

        int lHeight = height(root->left);
        int rHeight = height(root->right);

        int diff = lHeight - rHeight;
        if(diff < -1 || diff > 1) ans = false;

        return 1 + max(lHeight, rHeight);
    }
};
