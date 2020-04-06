class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<string> v[10001];
        map<string, int> mp;
        int id = 0;
        for (int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (mp[s])
                v[mp[s]].push_back(strs[i]);
            else
            {
                mp[s] = ++id;
                v[mp[s]].push_back(strs[i]);
            }
        }
        vector<vector<string>> ret;
        for (int i = 1; i <= id; i++)
            ret.push_back(v[i]);
        return ret;
    }
};