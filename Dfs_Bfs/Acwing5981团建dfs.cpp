#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;
const int M = N * 2;

int h[3][N], e[3][M], ne[3][M], idx1, idx2;
int w[3][N];

bool st1[N];
bool st2[N];

int n, m;
int res;

void add(int a, int b, int flag){
    if(flag == 1){
        e[1][idx1] = b; ne[1][idx1] = h[1][a]; h[1][a] = idx1++;
    }else if(flag == 2){
        e[2][idx2] = b; ne[2][idx2] = h[2][a]; h[2][a] = idx2++;
    }
}

void dfs(int a, int b, int cnt){
    
    res = max(res, cnt);
    
    st1[a] = st2[b] = true;
    
    for(int i = h[1][a]; i != -1; i = ne[1][i]){
        int u = e[1][i], w1 = w[1][u];
        if(!st1[u]){
            st1[u] = true;
            
            for(int j = h[2][b]; j != -1; j = ne[2][j]){
                int v = e[2][j], w2 = w[2][v];
                if(!st2[v]){
                    if(w1 == w2){
                        st2[v] = true;
                        dfs(u, v, cnt + 1);
                        st2[v] = false;
                    }
                }
            }
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    
    for(int i = 1; i <= n; i++) scanf("%d", &w[1][i]);
    for(int i = 1; i <= m; i++) scanf("%d", &w[2][i]);
    
    memset(h, -1, sizeof h);
    
    for(int i = 0; i < n - 1; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b, 1);
        add(b, a, 1);
    }
    for(int i = 0; i < m - 1; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b, 2);
        add(b, a, 2);
    }
    
    if(w[1][1] == w[2][1]){
        dfs(1,1,1);
    }
    
    printf("%d\n", res);
    
    return 0;
}