#include <iostream>
using namespace std;

int main()
{
    long long int TC, t=1;
    while(cin >> TC) {
        long long int i, j, arr[TC+10];
        long long  mxproduct=0, p;
        for(i=1; i<=TC; i++) { cin >> arr[i]; }
        arr[0]=1;
        arr[TC+1]=1;
        for(i=1; i<=TC; i++) {
            p = 1;
            for(j=i; j<=TC; j++) {
                p*=arr[j];
                if(p > mxproduct) mxproduct = p;
            }
        }
        cout << "Case #" << t << ": The maximum product is " << mxproduct << "." << endl;
        cout << endl;
        t++;
    }
    return 0;
}