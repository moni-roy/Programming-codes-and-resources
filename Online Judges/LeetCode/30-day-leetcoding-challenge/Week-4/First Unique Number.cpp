class FirstUnique
{
public:
    map<int, int> mp;
    deque<int> dq;
    FirstUnique(vector<int> &nums)
    {
        for (auto num : nums)
        {
            mp[num]++;
            if (mp[num] == 1)
                dq.push_back(num);
        }
    }

    int showFirstUnique()
    {
        if (dq.empty())
            return -1;
        while (!dq.empty() && mp[dq.front()] > 1)
        {
            dq.pop_front();
        }
        if (dq.empty())
            return -1;
        return dq.front();
    }

    void add(int value)
    {
        mp[value]++;
        if (mp[value] == 1)
            dq.push_back(value);
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */