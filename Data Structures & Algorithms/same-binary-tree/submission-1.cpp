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
    bool equivalency = true;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        preorder(p, q);
        return equivalency;
    }

    void preorder(TreeNode* p, TreeNode* q){
        if(!equivalency) return;
        if(p == nullptr && q == nullptr) return;
        if(p == nullptr && q != nullptr){
            equivalency = false;
            return;
        }
        if(p != nullptr && q == nullptr){
            equivalency = false;
            return;
        }
        if(p->val != q->val){
            equivalency = false;
        }

        preorder(p->left, q->left);
        preorder(p->right, q->right);

        
    }
};
