//https://codeforces.com/problemset/problem/474/D
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9+7;
int mem[100005];
int n,k,i,high;
int t1[100005],t2[100005];
int main(){
    scanf("%d%d",&n,&k);
    for (i = 0; i < n; i++){
        scanf("%d%d",&t1[i],&t2[i]);
        high = max(high,t2[i]);
    }
    mem[0] = 1;
    for (i = 1; i <= high; i++){
        if (i >= k) mem[i] = (mem[i]+mem[i-k])%INF; 
        mem[i] = (mem[i]+mem[i-1])%INF;
    }
    for (i = 1; i <= high; i++) mem[i] = (mem[i]+mem[i-1])%INF;
    for (i = 0; i < n; i++){
        printf("%d\n",(mem[t2[i]]-mem[t1[i]-1]+INF)%INF);
    }
}