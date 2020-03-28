#include <stdio.h>
int Min(int a,int b){return (a<b)?a:b;}
char s1[9],s2[9],s3[9];
int mp[200],number[11][4];
void Main(){
    scanf("%s %s %s",s1,s2,s3);
    mp['m'] = 1;
    mp['p'] = 2;
    mp['s'] = 3;
    number[s1[0]-'0'][mp[s1[1]]]++; 
    number[s2[0]-'0'][mp[s2[1]]]++;
    number[s3[0]-'0'][mp[s3[1]]]++;
    int Ans = 11;
    for(int i = 1;i<=9;i++){
        for(int j =1;j<=3;j++){
            Ans = Min(Ans,3-number[i][j]);
            if(i+2<=9) Ans = Min(Ans, !number[i][j]+!number[i+1][j]+!number[i+2][j]);
        }
    }
    printf("%d\n",Ans);
}
int main(){
    Main();
    return 0;
}