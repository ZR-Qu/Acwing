// 重练习，和 传纸条那题一样
#include <bits/stdc++.h>

using namespace std;

const int N = 20;
int n; //n取0-9，那么dp【N】中的N要取到20及以上
int a[N][N];
// int dp[N][N][N]; 
int dp[2*N][N][N]; //2*n!!!!!!!

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;

    int r, c, w;
    while(1){
        cin >> r >> c >> w;
        if(r == 0 && c == 0 && w == 0) break;
        a[r][c] = w;
    }

    memset(dp, -0x3f, sizeof dp);
    dp[1][1][1] = 0;

    for(int k = 2; k <= 2 * n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){

                //相比之前优化了一下越界的判断
                int y1 = k - i, y2 = k-j;
                if(y1 < 1 || y1 > n || y2 < 1|| y2 > n) continue;

                int res = dp[k-1][i][j];
                if(i > 1) res = max(res, dp[k-1][i-1][j]);
                if(j > 1) res = max(res, dp[k-1][i][j-1]);
                if(i > 1 && j > 1) res = max(res, dp[k-1][i-1][j-1]);

                res += a[i][k-i];
                if(i != j) res += a[j][k-j];

                dp[k][i][j] = res;
            }
        }
    }

    cout << dp[2*n][n][n] << endl;

    return 0;
}

