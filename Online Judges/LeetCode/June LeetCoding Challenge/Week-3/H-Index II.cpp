class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int l = 0, h = citations.size() - 1;
        int sz = h + 1;
        int k = h + 1;
        while (l <= h)
        {
            int m = l + (h - l) / 2;
            int cite = citations[m];
            if (cite >= (sz - m))
            {
                h = m - 1;
                k = m;
            }
            else
                l = m + 1;
        }
        return citations.size() - k;
    }
};