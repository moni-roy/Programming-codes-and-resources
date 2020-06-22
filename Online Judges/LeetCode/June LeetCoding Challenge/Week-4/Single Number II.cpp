class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int first = 0, second = 0;
        for (auto num : nums)
        {
            first = (num ^ first) & ~second;
            second = (num ^ second) & ~first;
        }
        return first;
    }
};