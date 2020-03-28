#include <bits/stdc++.h>
using namespace std;
 
bool LeapYear(int year)
{
    if(year%4==0)
    {
        if(year%100==0)
        {
            if(year%400==0)
            {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}
int MonthNumber(string month)
{
    if(month=="January")
        return 1;
    else if(month=="February")
        return 2;
    else if(month=="March")
        return 3;
    else if(month=="April")
        return 4;
    else if(month=="May")
        return 5;
    else if(month=="June")
        return 6;
    else if(month=="July")
        return 7;
    else if(month=="August")
        return 8;
    else if(month=="September")
        return 9;
    else if(month=="October")
        return 10;
    else if(month=="November")
        return 11;
    else if(month=="December")
        return 12;
    return 0;
}
int main()
{
    int t,cs=0,date1,date2,year1,year2;
    string month1,month2;
    cin>>t;
    while(t--)
    {
        cin>>month1>>date1;
        getchar();
        cin>>year1;
        cin>>month2>>date2;
        getchar();
        cin>>year2;
        int FirstMonth=MonthNumber(month1);
        int SecondMonth=MonthNumber(month2);
        int ans=((year2-year1)/400)*97;
        year1%=400;
        year2%=400;
        year1+=400;
        year2+=400;
        if(year2<year1)
        {
            year2+=400;
        }
        for(int i=year1;i<=year2;i++)
        {
            if(LeapYear(i))
                ans++;
        }
        if(LeapYear(year1))
        {
            if(FirstMonth>2)
            {
                ans--;
            }
        }
        if(LeapYear(year2))
        {
            if(SecondMonth<2)
            {
                ans--;
            }
            else if(SecondMonth==2&&date2<29)
                ans--;
        }
        cout<<"Case "<<++cs<<": "<<ans<<endl;
    }
    return 0;
}
            
