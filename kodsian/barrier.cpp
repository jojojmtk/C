#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 6e6+4;
int i,t;
int n,w;

struct node{
    ll maxleftsum, maxrightsum, sum, maxsum;
    int l,r,len;
    bool operator < (node t) const{
        return maxsum < t.maxsum;
    }
}tree[MAXN<<2];

node merge(node &l, node &r){
    node p;
    p.maxleftsum = max(l.maxleftsum, l.sum + r.maxleftsum);
    p.maxrightsum = max(r.maxrightsum, r.sum + l.maxrightsum);
    p.sum = l.sum + r.sum;
    p.maxsum = max({l.maxsum, r.maxsum, l.maxrightsum + r.maxleftsum});

    return p;
}
void add(int k, int x){
    k += n;
    tree[k].maxleftsum = tree[k].maxrightsum = tree[k].sum = tree[k].maxsum = x;
    tree[k].l = tree[k].r = tree[k].len = 1;
    for (k /= 2; k >= 1; k /= 2){
        tree[k] = merge(tree[2*k],tree[2*k+1]);
    }
}

ll query(int l, int r){
    ll sum = 0;
    l += n; r += n;
    while (l <= r){
        if (l % 2 == 1) sum = max(sum,tree[l++].maxsum);
        if (r % 2 == 0) sum = max(sum,tree[r--].maxsum);
        l /= 2; r /= 2;
    }
    return sum;
}
int main(){
    scanf("%d%d",&n,&w);
    for (i = 0; i < n; i++){
        scanf("%d",&t);
        add(i,t);
    }
    // for (i = 1; i < 2*n; i++) printf("%lld ",tree[i].maxsum);
    // cout<<"\n\n";
    for (i = 0; i < n-w+1; i++){
        cout << query(i,i+w-1)<<" ";
    }
}

/*
7 4
3
2
5
1
4
-7
10

7 3
3
2
5
1
4
-7
10
*/