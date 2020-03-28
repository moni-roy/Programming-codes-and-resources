 #include<bits/stdc++.h>
 #define ll long long int
 #define fr(i,a) for(i=0;i<a;i++)
 #define fr2(i,a,b) for(i=0;i<a;i+=b)
 #define mem(a,b) memset(a,b,sizeof(a))
 #define sci(a) scanf("%d",&a)
 #define scl(a) scanf("%lld",&a)
 #define pb() push_back()
 #define pt() printf()
 
 using namespace std;
 
 int main()
 {
	 int tst,ar[10000],num,i,ans,mid;
	 cin>>tst;
	 while(tst--)
	 {
		 cin>>num;
		 fr(i,num) cin>>ar[i];
		 sort(ar,ar+num);
		 if(num%2) mid=ar[num/2];
		 else mid=ar[num/2-1];
		 //cout<<mid<<endl;
		 ans=0;
		 fr(i,num) ans+=abs(ar[i]-mid);
		 cout<<ans<<endl;
	 }
	 return 0;
 }
