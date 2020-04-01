class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int x = 0;
        for (auto y : nums)
        {
            x ^= y;
        }
        return x;
    }
};
