#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MD=1e9+7;
const int mSize=2;
struct matrix{
    ll mat[mSize][mSize];
    void zero(){
        memset(mat,0,sizeof mat);
    }
    void identity(){
        for(int i=0; i<mSize; i++){
            for(int k=0; k<mSize; k++){
                mat[i][k]=(i==k);
            }
        }
    }
    friend matrix operator *(matrix a, matrix b){
        matrix result;
        result.zero();
        for(int i=0; i<mSize; i++){
            for(int k=0; k<mSize; k++){
                if(a.mat[i][k]){
                    for(int j=0; j<mSize; j++){
                        result.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
                        result.mat[i][j]%=MD;
                    }
                }
            }
        }
        return result;
    }
    friend matrix operator^(matrix a,ll x){
        matrix result;
        result.identity();
        while(x){
            if(x&1) result=result*a;
            a=a*a;
            x/=2;
        }
        return result;
    }
};
int main(){
    matrix base,xy;
    base.mat[0][0]=3;
    base.mat[0][1]=1;
    base.mat[1][1]=3;
    base.mat[1][0]=1;
    ll n;
    cin>>n;
	xy=(base^n);
	cout<<xy.mat[0][0]<<endl;
    return 0;
}
