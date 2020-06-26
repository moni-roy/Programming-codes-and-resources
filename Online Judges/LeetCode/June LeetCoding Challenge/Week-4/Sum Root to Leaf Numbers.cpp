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
    int ans = 0;
    void sumNumber(TreeNode *root, int sum)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            ans += (sum * 10 + root->val);
            return;
        }
        if (root->right)
            sumNumber(root->right, root->val + sum * 10);
        if (root->left)
            sumNumber(root->left, root->val + sum * 10);
    }
    int sumNumbers(TreeNode *root)
    {
        ans = 0;
        sumNumber(root, 0);
        return ans;
    }
};