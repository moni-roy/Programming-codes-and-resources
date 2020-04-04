class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        for (int i = 0, j = 0; i < nums.size(); i++)
        {
            if (j < i)
                j = i;
            while (j < nums.size() && nums[j] == 0)
                j++;
            if (j < nums.size() && i <= j && nums[i] == 0)
                swap(nums[i], nums[j]);
        }
    }
};