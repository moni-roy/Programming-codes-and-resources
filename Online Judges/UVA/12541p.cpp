/*---------------------------------------------------------.
 *                                                          *
 * Team-phoenix of JU                                       *
 *             Powered by RUM@HELP                          *
 * _________________________________________________________*/
#include<bits/stdc++.h>
#define ld double
#define ll long long int
#define llu long long unsigned
#define scldd(x,y) scanf("%lf%lf",&x,&y)
#define scld(x) scanf("%lf",&x)
#define scll(x,y) scanf("%lld%lld",&x,&y)
#define scl(x) scanf("%lld",&x)
#define sci(x) scanf("%d",&x)
#define scic(x,y) scanf(" %c %d",&x,&y)
#define scal(x,y,c,s) scanf("%lld%lld %c %s",&x,&y,&c,s)
#define sclll(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define scss(x,y) scanf("%s %s",x,y)
#define sc(s,d,m,y) scanf(" %s %d %d %d",s,&d,&m,&y)

using namespace std;

struct data
{
    char name[100];
    int date, mnth;
    int year;
    bool operator < ( const data& b ) const
    {
        if( year == b.year )
        {
            if( mnth == b.mnth )
            {
                return date > b.date;
            }
            else return mnth > b.mnth;
        }
        else return year > b.year;
    }
};
//bool compare( data a, data b )
//{
//    if( a.year == b.year )
//    {
//        if( a.mnth == b.mnth )
//        {
//            return a.date > b.date;
//        }
//        else return a.mnth > b.mnth;
//    }
//    else return a.year > b.year;
//}
int main()
{
    data arr[1100];
    int tst;
    sci(tst);
    for(int i=0; i<tst; i++)
    {
        sc(arr[i].name,arr[i].date,arr[i].mnth,arr[i].year);
    }
    sort(arr,arr+tst);
//    for(int i=0; i<tst; i++)
//    {
//        cout<<arr[i].name<<' ';
//    }
//    puts("");
    puts(arr[0].name);
    puts(arr[tst-1].name);
    return 0;
}
