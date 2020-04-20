/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *insert(TreeNode *root, int v)
    {
        if (root == NULL)
            return new TreeNode(v);
        if (root->val > v)
        {
            root->left = insert(root->left, v);
        }
        else
            root->right = insert(root->right, v);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        TreeNode *root = NULL;
        for (auto x : preorder)
        {
            root = insert(root, x);
        }
        return root;
    }
};
