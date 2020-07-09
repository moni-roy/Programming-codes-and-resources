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
    int maxLevel = 0;
    unsigned long long dfs(TreeNode *root, int level, unsigned long long id, vector<unsigned long long> &v)
    {
        if (root == nullptr)
            return 0;
        if (level >= v.size())
            v.push_back(id);
        return max({id + 1 - v[level], dfs(root->left, level + 1, id * 2, v), dfs(root->right, level + 1, 2 * id + 1, v)});
    }
    int widthOfBinaryTree(TreeNode *root)
    {
        vector<unsigned long long> v;
        return dfs(root, 0, 1, v);
    }
};