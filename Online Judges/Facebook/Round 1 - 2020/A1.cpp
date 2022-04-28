#include <bits/stdc++.h>
using namespace std;

int ts, cs = 0, n, k, w, al, bl, cl, dl, ah, bh, ch, dh, l[1000001], h[1000001], p[1000001];
int main()
{
    cin >> ts;
    while (ts--)
    {
        cin >> n >> k >> w;
        for (int i = 0; i < k; i++)
        {
            cin >> l[i];
        }
        cin >> al >> bl >> cl >> dl;
        for (int i = 0; i < k; i++)
        {
            cin >> h[i];
        }
        cin >> ah >> bh >> ch >> dh;
        for (int i = k; i < n; i++)
        {
            l[i] = ((al * l[i - 2]) % dl + (bl * l[i - 1]) % dl + cl) % dl + 1;
            h[i] = ((ah * h[i - 2]) % dh + (bh * h[i - 1]) % dh + ch) % dh + 1;
        }
        int L = -1;
        for (int i = 0; i < n; i++)
        {
            int ll = l[i] + w;
            if (L >= l[i])
            {
                p[i] = p[i - 1] + 2 * (h[i] + ll - L);
                p[i] -= 2 * min(h[i], h[i - 1]);
                L = ll;
            }
            else
            {
                p[i] = p[i - 1] + 2 * (w + h[i]);
                L = ll;
            }
        }
        for (int i = 0; i < n; i++)
            cout << l[i] << " ";
        cout << endl;
        for (int i = 0; i < n; i++)
            cout << h[i] << " ";
        cout << endl;
        for (int i = 0; i < n; i++)
            cout << p[i] << " ";
        cout << endl;
    }
}