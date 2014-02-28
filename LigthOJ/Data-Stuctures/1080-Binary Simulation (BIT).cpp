    #include <algorithm>
    #include <bitset>
    #include <cctype>
    #include <cmath>
    #include <complex>
    #include <cstdio>
    #include <cstdlib>
    #include <cstring>
    #include <ctime>
    #include <deque>
    #include <fstream>
    #include <iostream>
    #include <list>
    #include <map>
    #include <memory>
    #include <queue>
    #include <set>
    #include <sstream>
    #include <stack>
    #include <string>
    #include <utility>
    #include <vector>
    #include <iomanip>
    #include <numeric>
    #include <iterator>
    #include <typeinfo>
    #include <valarray>
    #include <functional>
    #include <cassert>
    #include <climits>
    using namespace std;
    int bit[1000009],num;
    bool ar[1000009];
    void inser(int pos,int val)
    {
    for(int i=pos; i<=num; i+=(i&-i))
    {
    bit[i]+=val;
    }
    }
    int query(int pos)
    {
    int sum=0;
    for(int i=pos; i>0; i-=(i&-i))
    {
    sum+=bit[i];
    }
    return sum;
    }
    void update(int x,int y)
    {
    inser(x,1);
    inser(y+1,-1);
    }
    int main()
    {
    int tst,qr,fm,hr,val,cas=0;
    scanf("%d",&tst);
    string nm;
    char ch;
    while(tst--)
    {
    printf("Case %d:\n",++cas);
    //getchar();
    cin>>nm;
    scanf("%d",&qr);
    num=nm.size();
    //memset(bit,0,sizeof bit);
    for(int i=0; nm[i]; i++)
    {
    ar[i]=nm[i]-'0';
    }
    memset(bit,0,sizeof bit);
    for(int i=0; i<qr; i++)
    {
    getchar();
    scanf("%c",&ch);
    if(ch=='Q')
    {
    scanf("%d",&val);
    printf("%d\n",ar[val-1] ^ (query(val)%2));
    }
    else
    {
    scanf("%d%d",&fm,&hr);
    update(fm, hr);
    }
    }
    }
    return 0;
    }
