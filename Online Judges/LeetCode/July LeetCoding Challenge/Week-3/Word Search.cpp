class Solution
{
public:
    bool dfs(vector<vector<char>> &board, string word, int pos, int x, int y)
    {
        if (pos == word.size())
            return true;
        if (x < 0 || y < 0 || x >= board.size() || y >= board[x].size() || board[x][y] != word[pos])
            return false;
        board[x][y] = '*';
        bool ret = dfs(board, word, pos + 1, x, y + 1);
        if (ret)
            return ret;
        ret = dfs(board, word, pos + 1, x, y - 1);
        if (ret)
            return ret;
        ret = dfs(board, word, pos + 1, x - 1, y);
        if (ret)
            return ret;
        ret = dfs(board, word, pos + 1, x + 1, y);
        if (ret)
            return ret;
        board[x][y] = word[pos];
        return ret;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (dfs(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
};