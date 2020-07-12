class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        vector<pair<int, double>> gr[n + 1];

        for (int i = 0; i < edges.size(); i++)
        {
            gr[edges[i][0]].push_back({edges[i][1], succProb[i]});
            gr[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        priority_queue<pair<double, int>> pq;
        vector<double> d(n, -1);
        vector<bool> u(n, false);
        pq.push({1, start});
        d[start] = 1;
        while (!pq.empty())
        {
            int v = pq.top().second;
            pq.pop();
            if (u[v])
                continue;
            u[v] = true;
            for (auto ed : gr[v])
            {
                int to = ed.first;
                double cs = ed.second;
                if (d[v] * cs > d[to])
                {
                    d[to] = d[v] * cs;
                    pq.push({d[to], to});
                }
            }
        }
        if (d[end] == -1)
            return 0;
        return d[end];
    }
};