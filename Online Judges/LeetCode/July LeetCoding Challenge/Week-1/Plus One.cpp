class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        reverse(digits.begin(), digits.end());
        int carry = 1;
        vector<int> ret;
        for (auto digit : digits)
        {
            carry += digit;
            ret.push_back(carry % 10);
            carry /= 10;
        }
        if (carry != 0)
            ret.push_back(carry);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};