#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const LL N = 5e5 + 10;

#define lc p << 1
#define rc p << 1 | 1

struct range{
    LL l,r;
    LL length;
    bool operator < (const range &w) const{
        return length < w.length;
    }
}range[N];

LL X[N*2]; // 存左右端点 ，同时离散化

// 线段树
struct tr {
    LL l,r,cnt; // cnt 重叠数
    LL lazy;
} tr[N * 8]; // (N * 2) * 4 因为左右节点 max = N * 2

LL n, m;
LL ans = 1e18;



void push_up(LL p) {
    tr[p].cnt = max(tr[lc].cnt, tr[rc].cnt);    //上传重叠数
}

void push_down(LL p) {
    if(tr[p].lazy){
        //更新重叠数
        tr[lc].cnt += tr[p].lazy;
        tr[rc].cnt += tr[p].lazy;
        //下传懒标记
        tr[lc].lazy += tr[p].lazy;
        tr[rc].lazy += tr[p].lazy;
        //删除父节点懒标记
        tr[p].lazy = 0;
    }
}

void build(LL p, LL l, LL r){
    tr[p] = {l, r, 0, 0};
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid+1, r);
    push_up(p);
}

void update(LL p, LL l, LL r, LL k){
    if(l > tr[p].r || r < tr[p].l) return; //如果要更新的不在p的区间内，返回
    if(l <= tr[p].l && tr[p].r <= r){ //如果全覆盖
        tr[p].cnt += k;
        tr[p].lazy += k;
        return;
    }
    push_down(p);
    update(lc, l, r, k);
    update(rc, l, r, k);
    push_up(p);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    
    for(LL i = 1; i <= n; i++){
        LL l, r;
        cin >> l >> r;
        range[i].l = l;
        range[i].r = r;
        range[i].length = r - l;

        X[i] = l, X[i+n] = r;
    }

    sort(range + 1, range + n + 1);
    sort(X + 1, X + 2*n + 1);

    int k = unique(X + 1, X + 2*n + 1) - X - 1; //去重后的端点个数

    for(int i = 1; i <= n; i++){
        range[i].l = lower_bound(X+1, X+k+1,range[i].l) - X;
        range[i].r = lower_bound(X+1, X+k+1,range[i].r) - X;
    }

    build(1,1,k);

    int i = 0, j = 0;
    while(i <= n){
        while(tr[1].cnt < m && i <=n){  //重叠数一直小于m就一直往窗口中加
            i++;
            update(1,range[i].l, range[i].r,1);
        }

        if(tr[1].cnt < m) break; //右指针指到最右还是满足不了条件，退出：ans = -1

        while(tr[1].cnt >= m && j <= i){ //满足重叠数>=m,缩小，但其实进入这个while时，cnt一定等于m
            j++;
            update(1,range[j].l, range[j].r, -1);
            ans = min(ans, range[i].length - range[j].length); // j从0开始，但是是1-based，所以 j 是最后被移出的索引
        }
    }

    if (ans == 1e18) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}