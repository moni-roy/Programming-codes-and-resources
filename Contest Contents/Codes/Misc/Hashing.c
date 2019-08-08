// Similar to Polynomial rolling hash
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