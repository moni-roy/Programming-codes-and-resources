class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int sz = nums.size();
        int lt[sz + 3], rt[sz + 3];
        for (int i = 0; i <= sz + 2; i++)
            lt[i] = rt[i] = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                lt[i + 1] = lt[i] + 1;
            }
        }
        for (int i = sz - 1; i >= 0; i--)
        {
            if (nums[i] == 1)
            {
                rt[i + 1] = rt[i + 2] + 1;
            }
        }
        int Ans = 0;
        for (int i = 1; i <= sz; i++)
        {
            Ans = max(lt[i - 1] + rt[i + 1], Ans);
        }
        return Ans;
    }
};