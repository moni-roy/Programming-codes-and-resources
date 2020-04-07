class Solution
{
public:
    bool present[10004];
    int countElements(vector<int> &arr)
    {
        for (auto item : arr)
        {
            present[item] = true;
        }
        int Ans = 0;
        for (auto item : arr)
        {
            if (present[item + 1])
                Ans++;
        }
        return Ans;
    }
};