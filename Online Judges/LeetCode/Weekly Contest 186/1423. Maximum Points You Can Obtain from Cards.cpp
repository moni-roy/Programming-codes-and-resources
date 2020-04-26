class Solution
{
public:
    int maxScore(vector<int> &nums, int k)
    {
        int mx = 0;
        vector<int> left(100010, 0), right(100010, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            left[i + 1] = left[i] + nums[i];
        }
        for (int i = nums.size(); i > 0; i--)
        {
            right[i] = right[i + 1] + nums[i - 1];
        }
        for (int i = 1; i <= k; i++)
        {
            mx = max(mx, left[i] + right[nums.size() - k + i + 1]);
        }

        for (int i = nums.size(); i > nums.size() - k; i--)
        {
            mx = max(mx, left[k - nums.size() + i - 1] + right[i]);
        }
        return mx;
    }
};