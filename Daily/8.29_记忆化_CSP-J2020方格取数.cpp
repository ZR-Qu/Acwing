// 70%样例，优化；前缀和
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const LL INF = 1e18;
const int N = 1010;

LL prefixsum[N][N];
LL f[N][N]; //f[i][j]状态表示：走完前j列，最后停在（i，j）的最优解

LL sum(int row1, int row2, int col){ // 计算row1~row2元素和
    if(row1 > row2) swap(row1, row2);
    return prefixsum[row2][col] - prefixsum[row1 - 1][col];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n,m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int a;
            cin >> a;
            prefixsum[i][j] = prefixsum[i-1][j] + a;    //用前缀和优化
        }
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            f[i][j] = -INF;
        }
    }
    f[1][0] = 0;

    for(int j = 1; j <= m; j++){    //按列来遍历！！！先j后i 
        for(int i = 1; i <= n; i++){
            for(int k = 1; k <= n; k++){
                f[i][j] = max(f[i][j], f[k][j-1] + sum(k, i, j));   
                //不是逐格模拟走法，转移时，我们只需要考虑“如何进入第 j 列”，竖走在 上一列 的代价，已经被计算进 f[k][j-1]
                //假设从$(k,j-1)$先向上/下走，走到了$(u,j-1)$，然后向右走了，最后走到了$(i,j)$，这种情况就等价于是从$(u,j-1)$走到$(i,j)$，因为从(k,j-1)到(u,j-1)会在计算f[u][j-1]的时候被计算到

                //按列分治，列分解，每次只考虑从第 j-1 列走到第 j 列，此时j-1列已经走完了，f[k][j-1]都已经是最优了，所以下一步只会是向右到下一列
            }
        }
    }

    cout << f[n][m];

    return 0;
}