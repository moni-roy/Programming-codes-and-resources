#include <stdio.h>
#define MOD 100003
#define SIZE 200006
int hashTable[SIZE];
long long count[SIZE];
void sort(char *t){
    for(int i = 0;i<10;i++){
        for(int j = i+1;j<10;j++){
            if(t[i]>t[j]){
                char c = t[i];
                t[i] = t[j];
                t[j] = c;
            }
        }
    }
}
int computeHash(char *t){
    int hash = 5381;
    int c;
    while(c=*t++){
        hash = ((hash<<5)%MOD + hash + c)%MOD;
    }
    return hash%MOD;
}
int compare(char *s1, char *s2){
    for(int i = 0;s1[i];i++){
        if(s1[i]!=s2[i]) return 0;
    }
    return 1;
}
char s[100020][21];
int getID(int hash,int id){
    while ( hashTable[hash]!=-1 )
    {
        int t = hashTable[hash];
        if(compare(s[t],s[id])) return hash;
        hash++;
        if(hash==SIZE) hash = 0;
    }
    return hash;
    
}
void init(){
    for(int i = 0;i<SIZE;i++) {
        hashTable[i] = -1;
        count[i] = 0;
    }
}
void MRoy(){
    init();
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%s",s[i]);
        sort(s[i]);
        int t = computeHash(s[i]);
        int id = getID(t,i);
        count[id]++;
        hashTable[id]=i;
    }
    long long int Ans = 0;
    for(int i = 0;i<SIZE;i++){
        Ans += (long long)(count[i]*(count[i]-1))/2;
    }
    printf("%lld\n",Ans);
    return;
}
int main(){
    MRoy();
    return 0;
}

/*
3
acornistnt
peanutbomb
constraint
*/