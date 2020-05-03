class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        int pr = -k - 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                if (i - pr <= k)
                    return false;
                pr = i;
            }
        }
        return true;
    }
};