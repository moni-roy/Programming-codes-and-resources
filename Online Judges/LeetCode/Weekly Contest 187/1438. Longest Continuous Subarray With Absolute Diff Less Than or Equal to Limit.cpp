class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        deque<pair<int, int>> max_dq, min_dq;
        int pr = -1, Ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int a = nums[i];
            while (!max_dq.empty() && max_dq.back().first < a)
                max_dq.pop_back();
            max_dq.push_back({a, i});
            while (!min_dq.empty() && min_dq.back().first > a)
                min_dq.pop_back();
            min_dq.push_back({a, i});
            while (!max_dq.empty() && !min_dq.empty())
            {
                int mx = max_dq.front().first;
                int mn = min_dq.front().first;
                if (mx - mn > limit)
                {
                    pr = min(max_dq.front().second, min_dq.front().second);
                    if (max_dq.front().second < min_dq.front().second)
                        max_dq.pop_front();
                    else if (max_dq.front().second > min_dq.front().second)
                        min_dq.pop_front();
                    else
                    {
                        max_dq.pop_front();
                        min_dq.pop_front();
                    }
                }
                else
                    break;
            }
            Ans = max(Ans, i - pr);
        }
        return Ans;
    }
};