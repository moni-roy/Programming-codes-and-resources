class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        vector<int> ret[100004];
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums[i].size(); j++)
            {
                ret[i + j].push_back(nums[i][j]);
            }
        }
        vector<int> Ans;
        for (int i = 0; i < 100001; i++)
        {
            int t = ret[i].size();
            while (t--)
            {
                Ans.push_back(ret[i].back());
                ret[i].pop_back();
            }
        }
        return Ans;
    }
};