class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maximum = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (sum + nums[i] < nums[i])
                sum = nums[i];
            else
                sum += nums[i];
            maximum = maximum < sum ? sum : maximum;
        }
        return maximum;
    }
};
