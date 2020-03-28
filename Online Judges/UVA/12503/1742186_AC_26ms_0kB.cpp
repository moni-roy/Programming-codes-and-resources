#include<bits/stdc++.h>

using namespace std;

int main()
{
    int tst,nu,sm,save[10000];
    string qr;
    int i;
    cin>>tst;
    while(tst--)
    {
        memset(save,0,sizeof(save));
        cin>>nu;
        getchar();
//        i=0;
        for(int j=0;j<nu;j++)
        {
        getline(cin,qr);
        if(qr=="LEFT")
        {
            save[j]=-1;

        }
        else if(qr=="RIGHT")
        {
            save[j]=1;
        }

        else
        {
            sm=0;
            for(int k=7;k<qr.size();k++)
            {
                if(qr[k]>='0'&&qr[k]<='9')
                {
                    sm=sm*10+(qr[k]-'0');
                }
            }
            save[j]=save[sm-1];
        }
        }
        int sum=0;
        for(i=0;i<nu;i++)
        {
         sum=sum+save[i];
    //cout<<save[i]<<endl;
        }
        cout<<sum<<endl;
    }

    return 0;
}
