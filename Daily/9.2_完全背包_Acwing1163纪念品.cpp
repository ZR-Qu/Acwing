#include <bits/stdc++.h>

using namespace std;

const int N = 110;
const int M = 10010;
int f[M];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t, n, m;
    cin >> t >> n >> m;

    int p[N][N];

    for(int i = 1; i <= t; i++){
        for(int j = 1; j <= n; j++){
            cin >> p[i][j];
        }
    }

    for(int i = 1; i < t; i++){
        memset(f, 0, sizeof f);

        for(int j = 1; j <= n; j++){
            if(p[i+1][j] <= p[i][j]) continue;
            for(int k = p[i][j]; k <= m; k++){
                f[k] = max(f[k], f[k - p[i][j]] + p[i+1][j] - p[i][j]);
            }
        }
        m += f[m];
    }

    cout << m;

    return 0;
}