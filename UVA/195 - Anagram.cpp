#include <bits/stdc++.h>
using namespace std;

bool cmp(char a,char b)
{
    if(toupper(a)==toupper(b)) return a<b;
    return toupper(a)<toupper(b);

}

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int ts;
    char s[1001];
    scanf("%d",&ts);
    while(ts--)
    {
        scanf("%s",s);
        int l=strlen(s);
        sort(s,s+l,cmp);
        do
        {
            printf("%s\n",s);
        }
        while(next_permutation(s,s+l,cmp));
    }
    return 0;
}
