#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int k = n - 2;
    cout << "*";
    for (int i = 0; i < k; i++) cout << " ";
    cout << "* *";
    for (int i = 0; i < k; i++) cout << "*";
    cout << "*" << endl;
    for (int j = 0; j < k; j++)
    {
        cout << "*";
        for (int i = 0; i < k; i++)
        {
            cout << " ";
        }
        cout << "* *";
        for (int i = 0; i < k; i++)
        {
            cout << " ";
        }
        cout << "*" << endl;
    }
    cout << "*";
    for (int i = 0; i < k; i++) cout << "*";
    cout << "* *";
    for (int i = 0; i < k; i++) cout << " ";
    cout << "*" << endl;
    return 0;
}
