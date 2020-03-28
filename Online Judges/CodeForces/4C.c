#include <stdio.h>
#define MX 200006
#define MOD 100003
int HashTable[MX],count[MX];
int computeHash(char *s){
    long long int hash = 5381;
    int c;
    while(c = *s++){
        hash = (c + (hash<<5)%MOD + hash)%MOD;
    }
    return hash%MOD;
}
char s[MOD][33];
int check(int i,int j){
    int k = 0;
    for(;s[i][k];k++){
        if(s[j][k]=='\0') return 0;
        if(s[i][k] != s[j][k]) return 0;
    }
    if(s[j][k]!='\0') return 0;
    return 1;

}
int getId(int hash, int id){
    while(HashTable[hash]!=-1){
        int t = HashTable[hash];
        if(check(t,id)){
            return hash;
        }
        hash++;
        if(hash==MX) hash = 0;
    }
    return hash;
}
void init()
{
    for(int i = 0;i<MX;i++) HashTable[i] = -1;
}
void MRoy(){
    init();
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%s",s[i]);
        int hash = computeHash(s);
        int t = getId(hash,i);
        HashTable[t] = i;
        count[t]++;
        if(count[t]==1) printf("OK\n");
        else printf("%s%d\n",s[i],count[t]-1);
    }
    return;
}
int main(){
    MRoy();
    return 0;
}