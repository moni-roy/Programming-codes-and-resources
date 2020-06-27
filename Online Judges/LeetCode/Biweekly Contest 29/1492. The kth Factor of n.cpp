class Solution
{
public:
    int kthFactor(int n, int k)
    {
        vector<int> fact;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                fact.push_back(i);
                if (i != n / i)
                    fact.push_back(n / i);
            }
        }
        sort(fact.begin(), fact.end());
        if (fact.size() < k)
            return -1;
        return fact[k - 1];
    }
};