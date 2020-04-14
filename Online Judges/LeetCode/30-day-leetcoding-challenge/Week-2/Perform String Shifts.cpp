class Solution
{
public:
    string stringShift(string s, vector<vector<int>> &shift)
    {
        int total = 0;
        for (auto x : shift)
        {
            if (x[0])
            {
                total += x[1];
            }
            else
                total -= x[1];
        }
        if (total < 0)
        {
            total *= -1;
            total %= s.size();
            if (total == 0)
                return s;
            string f = s.substr(0, total);
            string ss = s.substr(total);
            return ss + f;
        }
        else
        {
            total %= s.size();
            if (total == 0)
                return s;
            string f = s.substr(0, s.size() - total);
            string ss = s.substr(s.size() - total);
            return ss + f;
        }
    }
};