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
class Solution
{
public:
    int Ans = -1999999;
    int go(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int val = root->val;
        int left = go(root->left);
        int right = go(root->right);
        int ret = val + max(0, left) + max(0, right);
        Ans = (Ans < ret) ? ret : Ans;
        return val + max(0, max(right, left));
    }
    int maxPathSum(TreeNode *root)
    {
        Ans = -1e9;
        go(root);
        return Ans;
    }
};