#include <stdio.h>
#include <string.h>
#define MAXSIZE 5000005
unsigned long long Base = 29, base[MAXSIZE], hash[MAXSIZE];
void init(){
    base[0] = 1ULL;
    for(int i =1;i<MAXSIZE;i++){
        base[i] = base[i-1] * Base;
    }
}
void computeHash(char *str,int length){
    hash[0] = 0;
    for(int i = 0;i<length;i++){
        hash[i+1] = hash[i]*Base + str[i]-'a'+1;
    }
}
int okay(int length,int len,int p){
    unsigned long long first = hash[length];
    unsigned long long second = hash[p+length-1]-hash[p-1]*base[length];
    return (first==second);
}
int min(int x,int y){
    return (x<y)?x:y;
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
        int p;scanf("%d",&p);
        p++;
        int l = 1, r = min(p-1, len-p+1), Answer = 0;
        while(l<=r){
            int m = (l+r)>>1;
            if(okay(m,len,p)){
                Answer = m;
                l = m+1;
            }
            else r = m-1;
        }
        printf("%d\n",Answer);
    }
    return;
}
int main(){
    Main();
    return 0;
}