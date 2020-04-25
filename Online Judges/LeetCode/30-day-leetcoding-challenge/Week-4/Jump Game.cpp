class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int last = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (last < i)
                return false;
            last = max(last, i + nums[i]);
        }
        if (last >= nums.size() - 1)
            return true;
        return false;
    }
};