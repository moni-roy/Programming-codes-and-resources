class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int right = 0, down = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (i > 0)
                    right = grid[i - 1][j];
                if (j > 0)
                    down = grid[i][j - 1];
                grid[i][j] += min(right, down);
                right = down = 1e7;
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};