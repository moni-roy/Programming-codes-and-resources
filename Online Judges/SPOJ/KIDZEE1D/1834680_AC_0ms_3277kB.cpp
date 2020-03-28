#include<bits/stdc++.h>
using namespace std;
int main()
{
 int tst,cas=0,num;
 cin>>tst;
 while(tst--)
 {
   cin>>num;
   if(num>=80) {cout<<"Case "<<++cas<<": "; puts("A+");}
   else if(num>=75) {cout<<"Case "<<++cas<<": "; puts("A");}
   else if(num>=70) {cout<<"Case "<<++cas<<": "; puts("A-");}
   else if(num>=65) {cout<<"Case "<<++cas<<": "; puts("B+");}
   else if(num>=60) {cout<<"Case "<<++cas<<": "; puts("B");}
   else if(num>=55) {cout<<"Case "<<++cas<<": "; puts("B-");}
   else if(num>=50) {cout<<"Case "<<++cas<<": "; puts("C");}
   else if(num>=45) {cout<<"Case "<<++cas<<": "; puts("D");}
   else {cout<<"Case "<<++cas<<": "; puts("F");}
}
return 0;
}