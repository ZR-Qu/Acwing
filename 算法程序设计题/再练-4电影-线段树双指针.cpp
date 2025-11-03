#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const LL N = 5e5 + 10;

#define lc p << 1
#define rc p << 1 | 1 

struct range{
    LL l, r;
    LL len;

    bool operator < (const range&w) const{
        return len < w.len;
    }
}range[N];

struct tr{
    LL l, r, cnt;
    LL lazy;
}tr[N*2*4];

LL X[N*2];

void pushup(LL p){
    tr[p].cnt = max(tr[lc].cnt, tr[rc].cnt);
    return;
}

void pushdown(LL p){
    if(tr[p].lazy){
        tr[lc].cnt+=tr[p].lazy;
        tr[rc].cnt+=tr[p].lazy;
        tr[lc].lazy+=tr[p].lazy;
        tr[rc].lazy+=tr[p].lazy;
        tr[p].lazy = 0;
    }
    return;
}

void build(LL p, LL l, LL r){
    tr[p] = {l, r, 0, 0};
    if(l == r) return;
    LL mid  = (l+r) >> 1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    pushup(p);
}

void update(LL p, LL l, LL r, LL k){
    if(l <= tr[p].l && tr[p].r <=r){
        tr[p].cnt+=k;
        tr[p].lazy+=k;
        return;
    }
    pushdown(p);
    // LL mid = (l+r) >> 1;
    LL mid = (tr[p].l + tr[p].r) >> 1;
    if(l <= mid) update(lc,l,r,k);
    if(r > mid) update(rc,l,r,k);
    pushup(p);
    return;
}

LL n, m;
LL ans = 1e18;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for(LL i = 1; i <=n; i++){
        LL l, r;
        cin >> l >> r;
        range[i] = {l, r, r-l};
        X[i] = l; X[i+n] = r;
    }
    sort(range+1, range+n+1);
    sort(X+1, X+2*n+1);

    LL k = unique(X+1, X+2*n+1)-X-1;

    build(1,1,k-1);//右端点偏移映射

    for(LL i = 1; i <=n; i++){
        range[i].l = lower_bound(X+1,X+1+k,range[i].l) - X;
        range[i].r = lower_bound(X+1,X+1+k,range[i].r) - X;
    }

    for(int i = 1, j =1; i <= n; i++){
        update(1, range[i].l, range[i].r-1, 1);//右端点偏移映射

        while(tr[1].cnt >= m && j <= i){
            ans = min(ans, range[i].len-range[j].len);
            update(1,range[j].l,range[j].r-1,-1);
            j++;
        }
    }

    cout << (ans==1e18?-1:ans) << endl;

    return 0;
}