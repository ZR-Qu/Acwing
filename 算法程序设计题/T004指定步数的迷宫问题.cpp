#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const LL N = 10;

LL n, m, k;
LL a[N][N];
bool st[N][N];

LL dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

bool flag;

void dfs(LL x, LL y, LL step){
    if(flag || step > k) return;
    if(x == n-1 && y == m-1){
        if(step == k) flag = true;
        return;
    }

    for(int i = 0; i < 4; i++){
        int x1 = x + dx[i], y1 = y + dy[i];
        if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && a[x1][y1] == 0 && !st[x1][y1]){
            st[x1][y1] = true;
            dfs(x1, y1, step+1);
            st[x1][y1] = false;
        }
    }

    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    st[0][0] = true;
    dfs(0,0,0);

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}