
#include<bits/stdc++.h>
using namespace std;
bool palin(char s1[])
{
    int l=strlen(s1)-1;
    for(int i=0,j=l;i<=j;i++,j--)
    {
        if(s1[i]!=s1[j])return false;
    }
    return true;
}
bool mir(char s1[])
{
    char s2[10000];
    int l=strlen(s1)-1;
    for(int i=0;i<=l;i++)
    {
        if(s1[i]=='E')s2[i]='3';
        else if(s1[i]=='J')s2[i]='L';
        else if(s1[i]=='L')s2[i]='J';
        else if(s1[i]=='S')s2[i]='2';
        else if(s1[i]=='Z')s2[i]='5';
        else if(s1[i]=='2')s2[i]='S';
        else if(s1[i]=='3')s2[i]='E';
        else if(s1[i]=='5')s2[i]='Z';
        else if(s1[i]=='0')s2[i]='O';
        else if(s1[i]=='O')s2[i]='O';
        else if(s1[i]=='A')s2[i]='A';
        else if(s1[i]=='M')s2[i]='M';
        else if(s1[i]=='1')s2[i]='1';
        else if(s1[i]=='8')s2[i]='8';
        else if(s1[i]=='H')s2[i]='H';
        else if(s1[i]<='Y'&&s1[i]>='T')s2[i]=s1[i];
 
        else s2[i]=' ';
    }
    for(int i=0,j=l;i<=l;i++,j--)
    {
        if(s1[i]!=s2[j])return false;
    }
    return true;
}
int main()
{
    char s[10000];
    while(gets(s))
    {
        if(mir(s)==true && palin(s)==true)cout<<s<<" -- is a mirrored palindrome."<<endl<<endl;
        else if(mir(s)==true && palin(s)==false)cout<<s<<" -- is a mirrored string."<<endl<<endl;
        else if(mir(s)==false && palin(s)==true)cout<<s<<" -- is a regular palindrome."<<endl<<endl;
        else if(mir(s)==false && palin(s)==false)cout<<s<<" -- is not a palindrome."<<endl<<endl;
    }
    return 0;
}