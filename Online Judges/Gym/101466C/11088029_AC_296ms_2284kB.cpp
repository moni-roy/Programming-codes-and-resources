#include <bits/stdc++.h>
using namespace std;
const int MX = 5e3 + 10;
struct point
{
    long long x, y, z;
    point()
    {
        x = y = z = 0;
    }
    point(long long _, long long __, long long ___)
    {
        x = _, y = __, z = ___;
    }
};

point sub(point a, point b)
{
    return point(a.x - b.x, a.y - b.y, a.z - b.z);
}

point cross(point a, point b, point c)
{
    a = sub(a, c);
    b = sub(b, c);
    return point(a.y * b.z - a.z * b.y, -a.x * b.z + a.z * b.x, a.x * b.y - a.y * b.x);
}

long long area(point a)
{
    return a.x * a.x + a.y * a.y + a.z * a.z;
}

bool ok(point a)
{
    return area(a) == 0;
}
int pr[MX];
int fd(int p)
{
    return (p == pr[p]) ? p : pr[p] = fd(pr[p]);
}

void connect(int x, int y)
{
    int xx = fd(x);
    int yy = fd(y);
    if (xx == yy) return;
    pr[xx] = yy;
}

int main()
{
    ios_base::sync_with_stdio(0);
    point st;
    int n;
    cin >> n;
    cin >> st.x >> st.y >> st.z;
    vector<point>v(n - 1);
    for (auto &i : v)
    {
        cin >> i.x >> i.y >> i.z;
    }
    for (int i = 0; i <= n; i++) pr[i] = i;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (ok(cross(v[i], v[j], st)))
            {
                connect(i, j);
            }
        }
    }
    set<int>Ans;
    for (int i = 0; i < n - 1; i++)
    {
        Ans.insert(fd(i));
    }
    cout << Ans.size() << endl;
    return 0;
}
