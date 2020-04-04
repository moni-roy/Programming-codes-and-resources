#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ts, cs = 0;
    string s;
    cin >> ts;
    while (ts--)
    {
        cin >> s;
        string r = "", sb = "";
        int i = 0;
        while (i < s.size() && s[i] == '0')
        {
            r += s[i++];
        }
        char ch = '0';
        if (i < s.size())
            ch = s[i];
        int st = 0, en = 0;
        for (; i < s.size(); i++)
        {
            if (s[i] == ch)
            {
                sb += ch;
            }
            else
            {
                st = ch - '0';

                while (en > st)
                {
                    r += ")";
                    en--;
                }
                int t = en;
                while (st > t)
                {
                    st--;
                    en++;
                    r += "(";
                }
                r += sb;
                ch = s[i];
                sb = ch;
            }
        }
        st = ch - '0';
        if (en || st)
        {
            while (en > st)
            {
                r += ")";
                en--;
            }
            int t = en;
            while (st > t)
            {
                st--;
                en++;
                r += "(";
            }
            r += sb;
            while (en)
            {
                r += ")";
                en--;
            }
        }
        cout << "Case #" << ++cs << ": " << r << endl;
    }
}