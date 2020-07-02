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
    int mx = 0;
    vector<int> vec[10010];
    void dfs(TreeNode *root, int level)
    {
        if (root == nullptr)
            return;
        mx = max(mx, level);
        vec[level].push_back(root->val);
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        mx = -1;
        dfs(root, 0);
        vector<vector<int>> res;
        for (int i = mx; i >= 0; i--)
        {
            res.push_back(vec[i]);
        }
        return res;
    }
};