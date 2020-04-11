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
    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int left = height(root->left);
        int right = height(root->right);

        int lDiameter = diameterOfBinaryTree(root->left);
        int rDiameter = diameterOfBinaryTree(root->right);

        return max(left + right, max(lDiameter, rDiameter));
    }
};