class MyHashSet
{
public:
    /** Initialize your data structure here. */
    map<int, bool> mp;
    MyHashSet()
    {
        mp.clear();
    }

    void add(int key)
    {
        mp[key] = 1;
    }

    void remove(int key)
    {
        mp.erase(key);
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        if (mp.find(key) != mp.end())
            return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */