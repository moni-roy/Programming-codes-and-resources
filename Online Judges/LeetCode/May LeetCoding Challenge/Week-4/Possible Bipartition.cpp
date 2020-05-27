class Solution
{
public:
    vector<int> graph[2001];
    int color[2001];
    bool dfs(int u, int c = 0)
    {
        if (color[u] != -1)
            return color[u] == c;
        color[u] = c;
        bool ret = 1;
        for (auto v : graph[u])
        {
            ret &= dfs(v, c ^ 1);
        }
        return ret;
    }
    bool possibleBipartition(int N, vector<vector<int>> &dislikes)
    {
        memset(color, -1, sizeof color);
        for (auto dis : dislikes)
        {
            int u = dis[0];
            int v = dis[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int Ans = 1;
        for (int i = 1; i <= N; i++)
        {
            if (color[i] == -1)
            {
                Ans &= dfs(i, 0);
            }
        }
        for (int i = 1; i <= N; i++)
            graph[i].clear();
        return Ans;
    }
};