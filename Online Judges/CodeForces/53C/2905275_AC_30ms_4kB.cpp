#include <bits/stdc++.h>
using namespace std;
int main(){
    int number;
    cin>>number;
    int start=1,en=number;
    for(int i=0;i<number;i++)
    {
        if(i&1) cout<<start++<<" ";
        else cout<<en--<<" ";
    }
return 0;
}
