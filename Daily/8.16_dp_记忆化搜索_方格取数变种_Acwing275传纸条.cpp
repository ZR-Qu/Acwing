#include <bits/stdc++.h>

using namespace std;

const int N = 60;

int a[N][N];
int dp[2*N][N][N];  

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int m, n;
    cin >> m >> n;

    // 考虑边界问题，用1-based数组
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    
    //需要初始化边界为-INF，避免错误路径
    memset(dp, -0x3f, sizeof(dp));
    
    dp[1][1][1] = 0;  //dp[k][i][j] k为步数，由于均只能往右和下两个方向，故k,i两个变量便可以保证点唯一；为保证 k = 横坐标 + 纵坐标 匹配上，初始点的k从2开始取， i 表示在k步时A所在的行数，j表示k步时B所在的行数

    for(int k = 2; k <= m+n; k++){
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= m; j++){
                    dp[k][i][j] = max(max(dp[k-1][i-1][j-1],dp[k-1][i][j-1]),max(dp[k-1][i-1][j],dp[k-1][i][j])) + a[i][k-i];
                    // 状态转移方程 
                    // dp[k-1][i-1][j-1] --> 两者均往下走，其中A从(i-1, y)到(i, y), B从(j-1, y)到(j, y)
                    // dp[k-1][i][j-1]   --> A往右，B往下
                    // dp[k-1][i-1][j]   --> A往下，B往右
                    // dp[k-1][i][j]     --> 两者均往右走
    
                    if(i != j) dp[k][i][j] +=a[j][k-j]; //走了同一格时之加一遍，不同格才再加一遍
            }
        }
    }
    
    cout << dp[m+n][m][m];

    return 0;
}
