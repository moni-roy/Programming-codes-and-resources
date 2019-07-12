#include <stdio.h>

int check(int *a,int n)
{
    int f = 1;
    for(int i = 1;i<n;i++){
        if(a[i]<a[i-1]) f = 0;
    }
    return f;
}

int main(){
    int n; scanf("%d",&n);
    int a[100010]; 
    for(int i = 0;i<n;i++) scanf("%d",&a[i]);

    int u = 0,d=0,x=0,y=n;

    for(int i = 1;i<n-1;i++){
        if(a[i-1]<a[i] && a[i]>a[i+1]){ 
            if(x==0) x = i;
            u++;
        }
        if(a[i-1]>a[i] && a[i]<a[i+1]){
            d++;
            y=i;
        }
    }
    if(a[n-1]<a[n-2]) {
        d++;
        y = n-1;
    }
    if(a[0]>a[1]) {
        u++;
        x = 0;
    }
    // printf("%d %d\n %d %d \n",u,d,x,y);
    if(u == 0 && d == 0 ) puts("yes");
    else if(u == 1 && d == 1){
        /// swap
        int t = a[x];
        a[x] = a[y];
        a[y]=t;
        if(check(a,n)){
            puts("yes");
            printf("swap %d %d\n",x+1,y+1);
        }
        else{
            t = a[x];
            a[x] = a[y];
            a[y]=t;
            if(x>y) for(int j =x,k = y;k<j;k++,j--) t = a[k],a[k]=a[j],a[j]=t;
            else for(int j =y,k = x;k<j;k++,j--) t = a[k],a[k]=a[j],a[j]=t;
            if(check(a,n)){
                puts("yes");
                printf("reverse %d %d\n",x+1,y+1);
            }
            else puts("no");
        }
    }
    else if(d==2 && u == 2){
        int t;
        t = a[x];
        a[x] = a[y];
        a[y]=t;
        if(check(a,n)){
            puts("yes");
            printf("swap %d %d\n",x+1,y+1);
        }
        else puts("no");
    }
    else if(d==1 && u ==0){
        int t;
        for(int j =y,k = x;k<j;k++,j--) t = a[k],a[k]=a[j],a[j]=t;
        if(check(a,n)){
            puts("yes");
            printf("reverse %d %d\n",x+1,y+1);
        }
        else puts("no");
    }
    else if(d==0 && u == 1){
        int t;
        for(int j =x,k = y;k<j;k++,j--) t = a[k],a[k]=a[j],a[j]=t;
        if(check(a,n)){
            puts("yes");
            printf("reverse %d %d\n",x+1,y+1);
        }
        else puts("no");
    }
    else puts("no");
    return 0;
}
