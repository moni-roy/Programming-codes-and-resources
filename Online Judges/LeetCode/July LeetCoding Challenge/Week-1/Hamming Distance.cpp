class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int ret = 0;
        for (int i = 0; i < 32; i++)
        {
            if ((1 << i & x) != (1 << i & y))
                ret++;
        }
        return ret;
    }
};