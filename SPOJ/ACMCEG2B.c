#include <stdio.h>
#define MX 200003
#define MOD 100003
int HashTable[MX];
int computeHash(char *s){
    int hash = 5381;
    int c;
    while(c = *s++)
        hash = (c+1 + (hash<<5)%MOD + hash)%MOD;
    return hash%MOD;
}
int check(char *s1,char *s2){
    int i = 0;
    for(i = 0;s1[i];i++){
        if(s2[i]=='\0') return 0;
        if(s1[i]!=s2[i]) return 0;
    }
    if(s1[i]!=s2[i]) return 0;
    return 1;
}
char s[MOD][22],t[MOD][22];
void insertHash(int hash, int id,char *ch){
    while(HashTable[hash]!=-1){
        int d = HashTable[hash];
        if(check(ch,t[d])) 
        {
            HashTable[hash] = id;
            return;
        }
        hash ++;
        if(hash==MX) hash = 0;
    }
    HashTable[hash] = id;
}
int getHash(int hash,char *ch){
    while(1 ){
        int d = HashTable[hash];
        if(check(ch,t[d])) return d;
        hash ++;
        if(hash==MX) hash = 0;
    }
}
void init()
{
    for(int i = 0;i<MX;i++) HashTable[i] = -1;
}
int extra = 1000002;
void MRoy(){
    init();
    int n,a,b;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d %d %s",&a,&b,s[i]);
        a+=extra;
        b+=extra;
        int k = 0;
        while(a>0){
            t[i][k++] = (a%10+'0');
            a/=10;
        }
        while(b>0){
            t[i][k++] = (b%10+'0');
            b/=10;
        }
        t[i][k] = '\0';
        int hash = computeHash(t[i]);
        insertHash(hash,i,t[i]);
    }
    int q;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&a,&b);
        a+=extra;
        b+=extra;
        char ch[20];
        int k = 0;
        while(a>0){
            ch[k++] = (a%10+'0');
            a/=10;
        }
        while(b>0){
            ch[k++] = (b%10 +'0');
            b/=10;
        }
        ch[k] = '\0';
        int hash = computeHash(ch);
        int d = getHash(hash,ch);
        // printf("%s %d\n",ch,hash);
        printf("%s\n",s[d]);
    }
    return;
}
int main(){
    MRoy();
    return 0;
}