#include <bits/stdc++.h>
using namespace std;

string hex(char a)
{
	if(a=='0') return "0000";
	if(a=='1') return "0001";
	if(a=='2') return "0010";
	if(a=='3') return "0011";
	if(a=='4') return "0100";
	if(a=='5') return "0101";
	if(a=='6') return "0110";
	if(a=='7') return "0111";
	if(a=='8') return "1000";
	if(a=='9') return "1001";
	if(a=='A') return "1010";
	if(a=='B') return "1011";
	if(a=='C') return "1100";
	if(a=='D') return "1101";
	if(a=='E') return "1110";
	if(a=='F') return "1111";
}
int dec(string s)
{
	int k=0,dc=0;
	
	for(int i=12;i>=1;i--)
	{
		dc+=((s[i]-'0')*pow(2,k));
		k++;
	}
	return dc;
}
int main()
{
	int t,ln,lnn;
	string s,ss,bs,bss;
	char c;
	int ds,dss;
	cin>>t;
	while(t--)
	{
		cin>>s>>c>>ss;
		bs="";
		bss="";
		bs+='0';
		bss+='0';
		ln=s.size();
		if(ln==1)
		{
			bs+=hex('0');
			bs+=hex('0');
			bs+=hex(s[0]);
		}else if(ln==2)
		{
			bs+=hex('0');
			bs+=hex(s[0]);
			bs+=hex(s[1]);
		}
		else
		{
			bs+=hex(s[0]);
			bs+=hex(s[1]);
			bs+=hex(s[2]);
		}
		///snd
		lnn=ss.size();
		if(lnn==1)
		{
			bss+=hex('0');
			bss+=hex('0');
			bss+=hex(ss[0]);
		}else if(lnn==2)
		{
			bss+=hex('0');
			bss+=hex(ss[0]);
			bss+=hex(ss[1]);
		}
		else
		{
			bss+=hex(ss[0]);
			bss+=hex(ss[1]);
			bss+=hex(ss[2]);
		}
		ds=dec(bs);
		dss=dec(bss);
		if(c=='-')
		{
			cout<<bs<<" "<<c<<" "<<bss<<" = "<<ds-dss<<endl;
		}
		else cout<<bs<<" "<<c<<" "<<bss<<" = "<<ds+dss<<endl;
	}
}
/*
2
A + 3
AAA + BBB
* */
