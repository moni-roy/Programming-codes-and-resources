//asfaq//.............

#include <bits/stdc++.h>
using namespace std;
int coin[] = {1,5,10,25,50};
long long  DP[5][30150];

long long coinChange(int i, int amount)
{
    if (amount==0) return 1;
    if (i >= 5 || amount<0 ){
      return 0;
    }
    if (DP[i][amount] != -1) return DP[i][amount];
    long long int val1 = 0;
    val1=coinChange(i,amount-coin[i])+coinChange(i+1,amount);

    return DP[i][amount] = val1;
}

int main()
{
    int n;
    memset(DP,-1,sizeof(DP));
    while (scanf("%d",&n) == 1){
        long long cnt = coinChange(0,n);
    	if (cnt==1)
        	printf("There is only 1 way to produce %d cents change.\n",n);
        else  printf("There are %lld ways to produce %d cents change.\n",cnt,n);
    }


    return 0;
}
