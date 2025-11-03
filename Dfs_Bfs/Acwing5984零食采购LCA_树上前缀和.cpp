#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int foodno = 21;
const int N = 1e5 + 10;
const int M = N * 2;

int cnt[N][foodno]; //cnt[u][i] 存从root节点到u节点整条路径上物品i出现的次数
int f[N][20];   //fa[u][i] 节点u的向上跳2^i层的祖先节点; 2^20 ~ 1e6 此时大于N了
int depth[N];   //存每个节点的深度

int h[N], e[M], ne[M], idx; //罪魁祸首，e[],ne[] 最好都开2N算了，dubug半天

int n,c[N];

bool st[N];

int q[N];

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs_init(int u, int father){   //初始化fa[][]，depth[][]
    depth[u] = depth[father] + 1;
    
    f[u][0] = father;
    for(int i = 1; i <= 19; i++){
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    
    for(int i = h[u]; ~i; i = ne[i]){
        int v = e[i];
        if(v != father) dfs_init(v, u); //(v != father)  避免无向图不断重复
    }
}

void bfs(int root)
{
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[root] = 1;
    int hh = 0, tt = 0;
    q[0] = root;
    while (hh <= tt)
    {
        int t = q[hh ++ ];
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (depth[j] > depth[t] + 1)
            {
                depth[j] = depth[t] + 1;
                q[ ++ tt] = j;
                f[j][0] = t;
                for (int k = 1; k <= 19; k ++ )
                    f[j][k] = f[f[j][k - 1]][k - 1];
            }
        }
    }
}

void bfs2(int root){
    memset(depth, 0x3f ,sizeof depth);
    depth[0] = 0, depth[root] = 1; //辅助节点0，深度因为前面初始化所有depth为无穷了，需要重新初始化为0
    f[root][0] = 0;
    
    queue<int> q;
    q.push(root);
    
    while(q.size()){
        int t = q.front(); //优先队列才是q.top()
        q.pop();
        for(int i = h[t]; ~i; i = ne[i]){
            int u = e[i];
            if(depth[u] > depth[t] + 1){ //避免无向图不断循环，depth同时起到标记作用
                depth[u] = depth[t] + 1;
                
                f[u][0] = t;
                for(int j = 1; j <= 19; j++) f[u][j] = f[f[u][j - 1]][j - 1]; //在i的内层循环不要用i了，换成j，不然有歧义，段溢出
    
                q.push(u);
            }
        }
    }
}

int lca(int a, int b){
   if(depth[a] < depth[b]) swap(a,b);
   
   for(int i = 19; i >= 0; i--){
       if(depth[f[a][i]] >= depth[b]) a = f[a][i];
   }
   if(a == b) return b;
   
   for(int i = 19; i >= 0; i--){
       if(f[a][i] != f[b][i]) a = f[a][i], b = f[b][i]; //不是depth[f[a][i]] != depth[f[b][i]]
   }
   return f[b][0];
}

void dfs(int u){    //计算u的临界点的cnt[v][i]
    st[u] = true;
    
    for(int i = h[u]; ~i; i = ne[i]){
        int v = e[i];
        if(st[v]) continue;
        for(int j = 1; j <= 20; j++){ //物品no.
            cnt[v][j] = cnt[f[v][0]][j]; 
            if(c[v] == j) cnt[v][j]++;
        }
        //cnt[v][c[v]]++;
        dfs(v);
    }
}

int solve(int a, int b, int p){
    int res = 0;
    for(int i = 1; i <= 20; i++){
        int sum = cnt[a][i] + cnt[b][i] - 2 * cnt[p][i] + (c[p]== i);
        if(sum > 0) res++;
    }
    return res;
}

int main(){
    memset(h, -1, sizeof h);
    int m; // 前面队列用了q，这里再用会有歧义，段溢出
    scanf("%d%d", &n, &m);
    
    for(int i = 1; i <= n; i++) scanf("%d", &c[i]);
    
    for(int i = 0; i < n - 1; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a,b);
        add(b,a);
    }
    
    int root = 1;

    /*没必要，写了也对*/
    // depth[root] = 1;
    // f[root][0] = 0;

    cnt[root][c[root]] = 1;
    
    //bfs(1);
    //dfs_init(1,0);
    bfs2(root);

    dfs(1);
    
    for(int i = 0; i < m; i++){
        int s,t;
        scanf("%d%d", &s, &t);
        int pa = lca(s, t);
        int res = solve(s, t, pa);
        printf("%d\n", res);
    }
    
    return 0;
}