class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        map<long long, int> presum;
        long long sum = 0;
        int Ans = 0;
        for (auto num : nums)
        {
            sum += num;
            if (sum == k)
                Ans++;

            if (presum.find(sum - k) != presum.end())
            {
                Ans += presum[sum - k];
            }

            presum[sum]++;
        }
        return Ans;
    }
};