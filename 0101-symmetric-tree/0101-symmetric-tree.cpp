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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return mirror(root->left,root->right);
    }

    bool mirror(TreeNode*T1,TreeNode*T2){
        if(!T1 || !T2){
            return T1==T2;
        }
        if(T1->val != T2->val){
            return false;
        }
        return (mirror(T1->left,T2->right) && mirror(T1->right,T2->left));
    }
};