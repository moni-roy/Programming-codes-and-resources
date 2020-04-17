class Solution
{
public:
    int vis[1000][1000] = {0};
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void dfs(int x, int y, int nx, int ny, vector<vector<char>> &grid)
    {
        if (x < 0 || x > nx)
            return;
        if (y < 0 || y > ny)
            return;
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && xx <= nx && yy >= 0 && yy <= ny && grid[xx][yy] == '1' && vis[xx][yy] == 0)
                dfs(xx, yy, nx, ny, grid);
        }
        return;
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int nx = grid.size();
        if (nx == 0)
            return 0;
        int ny = grid[0].size();
        int Ans = 0;
        for (int i = 0; i < nx; i++)
        {
            for (int j = 0; j < ny; j++)
            {
                if (grid[i][j] == '1' && vis[i][j] == 0)
                {
                    Ans++;
                    dfs(i, j, nx - 1, ny - 1, grid);
                }
            }
        }
        return Ans;
    }
};