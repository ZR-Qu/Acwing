/*  B4016 树的直径
    https://www.luogu.com.cn/problem/B4016
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10;
int dp[N];
int mxd;

struct Edge{
    int to;
    int w;
    int ne;
}e[N];

int head[N], idx = 0;

void add(int u, int v, int w){
    e[idx] = {v, w, head[u]};
    head[u] = idx++;
    return;
}

void dfs(int x, int fa){
    for(int i = head[x]; ~i; i = e[i].ne){
        int v = e[i].to, w = e[i].w; 
        if(v == fa) continue;
        dfs(v, x);
        mxd = max(mxd, dp[x]+dp[v]+w);
        dp[x] = max(dp[x], dp[v]+w);
    }
}

int main(){
    ios::sync_with_stdio();
    memset(head, -1, sizeof head);

    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        add(u, v, 1);
        add(v, u, 1);
    }

    dfs(1,0);

    cout << mxd << endl;

    return 0;
}