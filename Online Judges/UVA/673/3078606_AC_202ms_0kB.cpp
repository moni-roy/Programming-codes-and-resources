#include <bits/stdc++.h>
using namespace std;
int ts, i, ln;

string st;
int main()
{
    cin >> ts;
    getchar();
    while(ts--)
    {
        stack<char>s;
        getline(cin ,st);
        ln = st.size();
        int flg = 0;
        for(i = 0; i < ln; i++)
        {
            if(st[i] == '(' || st[i] == '[')
            {
                s.push(st[i]);
            }
            else
            {
                //cout << s.empty() << endl;
                if(s.empty() == 1)
                {
                    flg = 1;
                    break;
                }
                else
                {
                    char x = s.top();
                    //cout << x << endl;
                    if((x =='('&&st[i]!=')')||(x =='['&&st[i]!=']'))
                    {
                        flg = 1;
                        break;
                    }
                    else
                        s.pop();
                }
            }
            // cout << s.top() << endl;
        }
        if(s.empty() == 1 && flg == 0)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}
