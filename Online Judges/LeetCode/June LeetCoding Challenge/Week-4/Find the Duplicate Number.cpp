class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int tortoise = nums[0], hare = nums[0];
        while (1)
        {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
            if (hare == tortoise)
                break;
        }
        tortoise = nums[0];
        while (tortoise != hare)
        {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        return hare;
    }
};