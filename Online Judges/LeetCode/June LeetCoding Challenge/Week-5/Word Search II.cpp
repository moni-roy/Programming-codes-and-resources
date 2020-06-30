struct trieNode
{
	string word = "";
	trieNode *next[26];
	trieNode()
	{
		word = "";
		for (int i = 0; i < 26; i++)
		{
			next[i] = nullptr;
		}
	}
};

class Solution
{
public:
	vector<vector<char>> board;
	vector<string> words, result;
	vector<string> findWords(vector<vector<char>> &bd, vector<string> &ws)
	{
		board = bd;
		words = ws;
		trieNode *root = buildTrie();
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				dfs(i, j, root);
			}
		}
		return result;
	}

	void dfs(int i, int j, trieNode *root)
	{
		char c = board[i][j];
		if (c == '#' || root->next[c - 'a'] == nullptr)
			return;
		root = root->next[c - 'a'];

		if (root->word != "")
		{
			result.push_back(root->word);
			root->word = "";
		}

		board[i][j] = '#';
		if (i > 0)
			dfs(i - 1, j, root);
		if (j > 0)
			dfs(i, j - 1, root);
		if (i < board.size() - 1)
			dfs(i + 1, j, root);
		if (j < board[0].size() - 1)
			dfs(i, j + 1, root);
		board[i][j] = c;
	}

	trieNode *buildTrie()
	{
		trieNode *root = new trieNode();
		for (auto w : words)
		{
			trieNode *tmp = root;
			for (auto c : w)
			{
				int t = c - 'a';
				if (tmp->next[t] == nullptr)
					tmp->next[t] = new trieNode();
				tmp = tmp->next[t];
			}
			tmp->word = w;
		}
		return root;
	}
};
