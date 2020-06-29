class Solution
{
public:
    map<string, multiset<string>> mp;
    vector<string> vec;
    void dfs(string u)
    {
        while (mp[u].size() != 0)
        {
            string v = *mp[u].begin();
            mp[u].erase(mp[u].begin());
            dfs(v);
        }
        vec.push_back(u);
    }
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        for (auto ticket : tickets)
        {
            mp[ticket[0]].insert(ticket[1]);
        }
        dfs("JFK");
        return vector<string>(vec.rbegin(), vec.rend());
    }
};