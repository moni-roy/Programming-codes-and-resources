const int MX = 500;
const int MC = 26;
int out[MX], flr[MX], gt[MX][MC];
int buildMatchingMachine(string ar[], int k)
{
    memset(out, 0, sizeof out);
    memset(gt, -1, sizeof gt);
    int states = 1;
    for (int i = 0; i < k; i++)
    {
        const string &word  = ar[i];
        int curState = 0;
        for (int j = 0; j < (int)word.size(); ++j)
        {
            int ch = word[j] - 'a'; // Uppercase --> 'A'
            if (gt[curState][ch] == -1)
            {
                gt[curState][ch] = states++;
            }
            curState = gt[curState][ch];
        }
        out[curState] |= (1 << i);
    }
    for (int ch = 0; ch < MC; ++ch)
    {
        if (gt[0][ch] == -1) gt[0][ch] = 0;
    }
    memset(flr, -1, sizeof flr);
    queue<int>q;
    for (int ch = 0; ch < MC; ++ch)
    {
        if (gt[0][ch] != 0)
        {
            flr[gt[0][ch]] = 0;
            g.push(gt[0][ch]);
        }
    }
    while (q.size())
    {
        int state = q.front();
        q.pop();
        for (int ch = 0; ch <= MC; ++ch)
        {
            if (gt[state][ch] != -1)
            {
                int fail = flr[state];
                while (gt[fail][ch] == -1) fail = flr[fail];
                fail = gt[fail][ch];
                flr[gt[state][ch]] = fail;
                out[gt[state][ch]] |= out[fail];
                q.push(gt[state][ch]);
            }
        }
    }
    return states;
}
int findNextState(int curState, char nextInput)
{
    int ans = curState;
    int ch = nextInput - 'a'; // Uppercase --> 'A'
    while (gt[ans][ch] == -1) ans = flr[ans];
    return gt[ans][ch];
}
void searchWords(string ar[], int k, string txt)
{
    buildMatchingMachine(ar, k);
    int curState = 0;
    for (int i = 0; i < (int)txt.size(); ++i)
    {
        curState = findNextState(curState, txt[i]);
        if (out[curState] == 0) continue;
        for (int j = 0; j < k; ++j)
        {
            if (out[curState] & (1 << j))
            {
                cout << ar[j] << "->" << i - ar[j].size() + 1 << endl;
            }
        }
    }
}
