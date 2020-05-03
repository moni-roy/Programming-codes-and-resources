class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        map<string, string> mp;
        string ans;
        for (auto path : paths)
        {
            ans = path[0];
            mp[path[0]] = path[1];
        }
        while (mp.find(ans) != mp.end())
        {
            ans = mp[ans];
        }
        return ans;
    }
};