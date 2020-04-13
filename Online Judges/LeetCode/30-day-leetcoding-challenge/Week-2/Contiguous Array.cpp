class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        map<int, int> mp;
        int len = 0, count = 0;
        mp[0] = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            count = count + (nums[i] ? 1 : -1);
            auto fnd = mp.find(count);
            if (fnd != mp.end())
            {
                len = (i - mp[count]) > len ? i - mp[count] : len;
            }
            else
                mp[count] = i;
        }
        return len;
    }
};