class UndergroundSystem
{
public:
    map<string, int> stringId;
    int sid;
    map<pair<int, int>, long long> total, count;
    int checkin[1000100];
    int check[1000010];

    UndergroundSystem()
    {
        stringId.clear();
        sid = 0;
        total.clear();
        count.clear();
    }

    void checkIn(int id, string stationName, int t)
    {
        checkin[id] = t;
        if (stringId.find(stationName) == stringId.end())
        {
            stringId[stationName] = sid++;
        }
        check[id] = stringId[stationName];
    }

    void checkOut(int id, string stationName, int t)
    {
        if (stringId.find(stationName) == stringId.end())
        {
            stringId[stationName] = sid++;
        }

        total[{max(stringId[stationName], check[id]), min(stringId[stationName], check[id])}] += t - checkin[id];
        count[{max(stringId[stationName], check[id]), min(stringId[stationName], check[id])}]++;
    }

    double getAverageTime(string startStation, string endStation)
    {
        return 1.0 * ((total[{max(stringId[startStation], stringId[endStation]), min(stringId[startStation], stringId[endStation])}] + 0.0) / count[{max(stringId[startStation], stringId[endStation]), min(stringId[startStation], stringId[endStation])}]);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
