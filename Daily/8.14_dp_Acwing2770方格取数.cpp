#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int a[N][N];
int dp[N][N];

using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(a, 0, sizeof a);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    
    memset(dp, 0, sizeof dp);
    dp[1][1] = a[1][1];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            // dp[i][j] = max(dp[i][j],);
        
        }
    }

    return 0;
}