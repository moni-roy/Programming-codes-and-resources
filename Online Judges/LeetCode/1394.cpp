class Solution
{
public:
    int ar[557];
    int findLucky(vector<int> &arr)
    {

        for (int i = 1; i < 555; i++)
            ar[i] = 0;
        for (auto x : arr)
        {
            ar[x]++;
        }
        for (int i = 501; i >= 1; i--)
        {
            if (ar[i] == i)
                return i;
        }
        return -1;
    }
};
