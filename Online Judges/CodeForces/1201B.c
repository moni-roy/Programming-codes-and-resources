#include <stdio.h>
#include <stdlib.h>
#define MXSIZE 100010
long long size, array[MXSIZE], max, sum;
void Main(){
    scanf("%lld", &size);
    for(int i = 0;i<size;i++){
        scanf("%lld",array+i);
        sum += array[i];
        if(i == 0 ) max = array[0];
        max = (max < array[i])? array[i]:max;
    }
    if(sum % 2 == 0 && 2*max <= sum) puts("YES");
    else puts("NO");
}
int main(){
    Main();
    return 0;
}