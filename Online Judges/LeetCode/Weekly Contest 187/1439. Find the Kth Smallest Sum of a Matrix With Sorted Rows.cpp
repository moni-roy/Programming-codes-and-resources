class Solution
{
public:
    int kthSmallest(vector<vector<int>> &mat, int k)
    {
        vector<int> presum(1);
        for (auto vec : mat)
        {
            vector<int> temp;
            for (auto value : vec)
            {
                for (auto pre : presum)
                {
                    temp.push_back(value + pre);
                }
            }
            sort(temp.begin(), temp.end());
            if (temp.size() > k)
                temp.resize(k);
            presum = temp;
        }
        return presum.back();
    }
};