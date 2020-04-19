class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;
            if ((nums[low] <= target && target <= nums[mid]) || (nums[mid] <= nums[high] && (nums[high] < target || nums[mid] > target)))
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
            cout << mid << " " << low << " " << high << endl;
        }
        return -1;
    }
};