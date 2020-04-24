class LRUCache
{
public:
    int cap = 0;
    map<int, int> mp;
    list<int> lis;
    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            lis.remove(key);
            lis.push_back(key);
            return mp[key];
        }
        else
            return -1;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            lis.remove(key);
        }
        if (cap == lis.size())
        {
            mp.erase(lis.front());
            lis.pop_front();
        }
        lis.push_back(key);
        mp[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */