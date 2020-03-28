#include<bits/stdc++.h>
#define ld double
#define ll long long int
#define scldd(x,y) scanf("%lf%lf",&x,&y)
#define scld(x) scanf("%lf",&x)
#define scll(x,y) scanf("%lld%lld",&x,&y)
#define scl(x) scanf("%lld",&x)
#define sci(x) scanf("%d",&x)
#define scic(x,y) scanf(" %c %d",&x,&y)
#define scal(x,y,c,s) scanf("%lld%lld %c %s",&x,&y,&c,s)
#define sclll(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define scs(x,y) scanf("%s %s",x,y)

using namespace std;

int fuc(char str[])
{
	return ((((str[0]-'0')*10+(str[1]-'0'))*60)+((str[3]-'0')*10)+(str[4]-'0'));
}
int main()
{
	char ms1[10],ms2[10],meet1[10],meet2[10];
	int tst,cas=0;
	sci(tst);
	while(tst--)
	{
		scs(ms1,ms2);
		scs(meet1,meet2);
		if(fuc(ms1)>fuc(meet2)||fuc(ms2)<fuc(meet1))
		{
			cout<<"Case "<<++cas<<": Hits Meeting"<<endl;
		}
		else cout<<"Case "<<++cas<<": Mrs Meeting"<<endl;
	}
	return 0;
}
