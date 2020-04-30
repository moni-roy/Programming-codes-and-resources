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
    bool check(TreeNode *root, vector<int> &arr, int sz)
    {
        if (sz == arr.size())
            return 0;
        int ret = 0;
        if (root->val == arr[sz])
        {
            if (root->left)
            {
                ret |= check(root->left, arr, sz + 1);
            }
            if (root->right)
            {
                ret |= check(root->right, arr, sz + 1);
            }
            if (root->left == nullptr && root->right == nullptr)
            {
                if (sz == arr.size() - 1)
                    ret = 1;
            }
        }
        return ret;
    }
    bool isValidSequence(TreeNode *root, vector<int> &arr)
    {
        return check(root, arr, 0);
    }
};