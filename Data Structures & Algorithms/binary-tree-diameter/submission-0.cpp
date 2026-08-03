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

private:
    int diameter = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int height = maxHeight(root);

        return diameter;
    }

    int maxHeight(TreeNode* root){
        if(root == nullptr) return 0;

        int left = maxHeight(root->left);
        int right = maxHeight(root->right);

        diameter = max(diameter, left + right);

        return 1 + max(left, right);
    }
};
