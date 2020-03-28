#include <stdio.h>
#include <string.h>
#define MAXSIZE 100002
unsigned long long Base = 127, base[MAXSIZE], hash[MAXSIZE];

void init(){
    base[0] = 1ULL;
    for(int i =1;i<MAXSIZE;i++){
        base[i] = base[i-1] * Base;
    }
}
void computeHash(char *str,int length){
    hash[0] = 0;
    for(int i = 0;i<length;i++){
        hash[i+1] = hash[i]*Base + str[i];
    }
}
unsigned long long computeHashPattern(char *str,int length){
    unsigned long long ret = 0;
    for(int i = 0;i<length;i++){
        ret = ret*Base + str[i];
    }
    return ret;
}
void Main(){
    init();
    char str[MAXSIZE];
    scanf("%s",str);
    int len = strlen(str);
    computeHash(str, len);
    int q; scanf("%d",&q);
    while (q--)
    {
        char p[2002];
        scanf("%s",p);
        int ln = strlen(p);
        unsigned long long hsh = computeHashPattern(p,ln);
        int f = 1;
        for(int i = 0;i<=len-ln;i++){
            unsigned long long y = hash[i+ln]-hash[i]*base[ln];
            if(hsh == y) {
                printf("Y\n");
                f=0;
                break;
            }
        }
        if(f) puts("N");
    }
    return;
}
int main(){
    Main();
    return 0;
}