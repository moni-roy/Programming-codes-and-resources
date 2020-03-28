#include<bits/stdc++.h>
using namespace std;
int ar[100],ar2[100],grap[50][50];
//void fstinput(int num)
//{
//    int mn;
////    for(int i=1; i<=num; i++)
////    {
////        cin>>mn;
////        ar[mn]=i;
////    }
//}
int main()
{
    int num;
    cin>>num;
//    fstinput(num);
    int in,mn;
    for(int i=1; i<=num; i++)
    {
        cin>>mn;
        ar[mn]=i;
    }
    while(cin>>in)
    {
        ar2[in]=1;
        for(int i=2;i<=num;i++)
        {
            cin>>mn;
            ar2[mn]=i;
        }
        for(int i=1;i<=num;i++)
        {
            for(int j=1;j<=num;j++)
            {
                if(ar[i]==ar2[j])
                {
                    grap[i][j]=grap[i-1][j-1]+1;

                }
                else
                {
                    grap[i][j]=max(grap[i-1][j],grap[i][j-1]);
                }
            }
        }
        cout<<grap[num][num]<<endl;
        memset(grap,0,sizeof grap);
    }

    return 0;
}
//first input
//4
//4 2 3 1
//1 3 2 4
//3 2 1 4
//2 3 4 1
//first output
//1
//2
//3
// second input
//10
//3 1 2 4 9 5 10 6 8 7
//1 2 3 4 5 6 7 8 9 10
//4 7 2 3 10 6 9 1 5 8
//3 1 2 4 9 5 10 6 8 7
//2 10 1 3 8 4 9 5 7 6
//second output
//6
//5
//10
//9
