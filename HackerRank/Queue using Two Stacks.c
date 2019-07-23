#include <stdio.h>

void solve(){
    int q, value, type, top1=-1, top2 = -1, stack1[100020],stack2[100010];
    scanf("%d",&q);
    while(q--){
        scanf("%d",&type);
        if(type==1){
            scanf("%d",&value);
            stack1[++top1] = value;
        }
        else{
            if(top2<0){
                while(top1>=0){
                    stack2[++top2] = stack1[top1--];
                }
            }
            if(type==2){
                top2--;
            }
            else{
                printf("%d\n",stack2[top2]);
            }

        }
    }
}
int main(){
    solve();
    return 0;
}

