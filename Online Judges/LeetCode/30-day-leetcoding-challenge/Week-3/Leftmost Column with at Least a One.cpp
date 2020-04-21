/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution
{
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix)
    {
        vector<int> dimensions = binaryMatrix.dimensions();
        int n = 0;
        int m = dimensions[1] - 1;
        while (n < dimensions[0] && m >= 0)
        {
            int t = binaryMatrix.get(n, m);
            if (t == 1)
            {
                m--;
            }
            else
            {
                n++;
            }
        }
        if (n == dimensions[0] - 1)
            return m + 1;
        if (n >= dimensions[0] && m == dimensions[1] - 1)
            return -1;
        return m + 1;
    }
};