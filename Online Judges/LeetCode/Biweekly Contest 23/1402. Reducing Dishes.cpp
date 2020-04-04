class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        long long sm = 0, mx = 0;
        int sz = satisfaction.size();
        for (int i = 0; i < sz; i++)
        {
            long long t = 1;
            sm = 0;
            for (int j = i; j < sz; j++)
            {
                sm += satisfaction[j] * t;
                t++;
            }
            mx = max(sm, mx);
        }
        return mx;
    }
};