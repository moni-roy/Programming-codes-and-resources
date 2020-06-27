class Solution
{
public:
    double average(vector<int> &salary)
    {
        int n = salary.size();
        sort(salary.begin(), salary.end());
        double sm = 0;
        for (int i = 1; i < n - 1; i++)
        {
            sm += salary[i];
        }
        return sm / (n - 2);
    }
};