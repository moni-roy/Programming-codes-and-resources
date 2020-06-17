class Solution
{
public:
    int par[40001];

    int find(int p)
    {
        return par[p] == p ? p : find(par[p]);
    }
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        if (n == 0)
            return;
        int m = board[0].size();
        for (int i = 0; i < 40001; i++)
            par[i] = i;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && board[i][j] == 'O')
                {
                    int u = i * m + j;
                    int v = n * m;
                    par[find(u)] = find(v);
                }
                else if (board[i][j] == 'O')
                {
                    if (board[i][j - 1] == 'O')
                    {
                        int u = i * m + j;
                        int v = i * m + j - 1;
                        par[find(u)] = find(v);
                    }
                    if (board[i][j + 1] == 'O')
                    {
                        int u = i * m + j;
                        int v = i * m + j + 1;
                        par[find(u)] = find(v);
                    }
                    if (board[i + 1][j] == 'O')
                    {
                        int u = i * m + j;
                        int v = (i + 1) * m + j;
                        par[find(u)] = find(v);
                    }
                    if (board[i - 1][j] == 'O')
                    {
                        int u = i * m + j;
                        int v = (i - 1) * m + j;
                        par[find(u)] = find(v);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int u = i * m + j;
                int v = n * m;
                if (par[find(u)] != find(v))
                {
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};