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
    int index = 0;

    TreeNode* build(vector<int>& preorder, int bound) {
        if (index == preorder.size())
            return NULL;

        if (preorder[index] > bound)
            return NULL;

        TreeNode* root = new TreeNode(preorder[index]);
        index++;

        root->left = build(preorder, root->val);
        root->right = build(preorder, bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MAX);
    }
};