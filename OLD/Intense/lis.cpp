#include <bits/stdc++.h>
using namespace std;
int a[2000],mem[1000][1000],mem2[1000][1000],ans,n;
int lis(int i, int last){
    if (i == n) return 0;
    if (!mem[i][last]){

        if (a[i] > last) mem[i][last] = lis(i+1,a[i]) + 1;
        mem[i][last] = max(mem[i][last],lis(i+1,last));
    }
    return mem[i][last];
}
int lds(int i, int last){
    if (i == n) return 0;
    if (!mem2[i][last]){

        if (a[i] < last) mem2[i][last] = lds(i+1,a[i]) + 1;
        mem2[i][last] = max(mem2[i][last],lds(i+1,last));
    }
    return mem2[i][last];
}
int main(){
    int i;
    scanf("%d",&n);
    for (i = 0; i < n; i++)
        scanf("%d",&a[i]);
    //ans = max(ans,lis(0,0) + lds(0,0) - 1);
    printf("%d %d",lis(0,0),lds(0,0));
    printf("%d",ans);
}
