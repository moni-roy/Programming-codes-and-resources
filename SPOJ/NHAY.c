#include <stdio.h>
#include <string.h>
#define MXSIZE 100009
const long long Base = 29;
const long long MOD = 1e9+9;

long long base[MXSIZE], hash[MXSIZE];

void init(){
    base[0] = 1ll;
    for(int i = 1;i<MXSIZE;i++){
        base[i] = (base[i-1] * Base) % MOD;
    }
}
long long computeHash(char *str,int length){
    hash[0] = 0ll;
    for(int i = 0;i<length;i++){
        hash[i+1] = (hash[i]*Base + (str[i]-'a'+1))%MOD;
    }
    return hash[length];
}
char haystack[MXSIZE], needle[MXSIZE];
void Main(){
    init();
    int length;
    while(scanf("%d",&length)==1){
        getchar();
        gets(needle);
        gets(haystack);
        long long hashNeedle = computeHash(needle, length);
        int lengthHaystack = strlen(haystack);
        computeHash(haystack, lengthHaystack);
        int flag = 0;
        for(int i=0; i < lengthHaystack - length+2; i++){
            long long subHash = (hash[i+length] + MOD - (hash[i] * base[length])%MOD)%MOD;
            if(subHash==hashNeedle) flag = 1,printf("%d\n",i);
        }
        if(!flag) puts("");
    }
}
int main(){
    init();
    Main();
    return 0;
}