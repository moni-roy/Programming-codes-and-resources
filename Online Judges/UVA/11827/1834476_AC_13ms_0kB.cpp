/*---------------------------------------------------------.
 * 															*
 * Team-phoenix of JU										*
 *             Powered by RUM@HELP							*
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


using namespace std;
int GCD(int x,int y)
{
	if(y==0) return x;
	else  return GCD(y,x%y);
}
char num[100000];
int main()
{
	int tst;

	sci(tst);
	getchar();
	while(tst--)
	{
		gets(num);
		stringstream ss(num);
		int mk;
		vector<int>nm;
		while(ss>>mk) nm.push_back(mk);
		int len=nm.size();
		int mxv=0;
		for(int i=0;i<len-1;i++)
		{
			for(int j=i+1;j<len;j++)
			{
				mxv=max(mxv,GCD(nm[i],nm[j]));
			}
		}
		cout<<mxv<<endl;
	}
	return 0;
}
