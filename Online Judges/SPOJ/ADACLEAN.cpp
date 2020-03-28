#include <bits/stdc++.h>
using namespace std;
#define MXSIZE 100009
const unsigned long long Base = 29;
int testCase,length, subLength;
char str[MXSIZE];
unsigned long long hash[MXSIZE],base[MXSIZE];
void init(){
    base[0]=1ULL;
    for(int i = 1;i<MXSIZE;i++){
        base[i] = base[i-1]*Base;
    }
}
void computeHash(char *st, int len){
    hash[0]=0;
    for(int i = 1;i<=len;i++){
        hash[i] = hash[i-1]*Base + (st[i-1]-'a'+1);
    }
}
void Main(){
	init();
    scanf("%d",&testCase);
    while (testCase--){
        scanf("%d%d",&length, &subLength);
        scanf("%s",str);
        computeHash(str, length);
		set<unsigned long long> uni;
        for(int i = 0;i<=length-subLength;i++){
            unsigned long long sub = hash[i+subLength]-hash[i]*base[subLength];
			uni.insert(sub);
        }
		printf("%d\n", uni.size());
    }
    return;
}
int main(){
    Main();
    return 0;
}
