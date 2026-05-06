/*  P8783 [蓝桥杯 2022 省 B] 统计子矩阵
    https://www.luogu.com.cn/problem/P8783
*/
/*  problem1：(a,b)~(c,d) a==c && b==d 即为1*1矩阵
    problem2：优化 O(n^2m^2) -> O(n^2m) 把m^2拆成两个o(m)，预处理
    problem3：双指针写法:
            int l = 1;
            LL sum = 0;
            for(int r = 1; r <= m; r++){
                sum += sum_col[r];
                while(sum > k){
                    sum -= sum_col[l];
                    l++;
                }
                cnt += r - l + 1;
            }
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 510;

LL a[N][N];
LL sum_col[N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    LL n, m, k;
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }

/*  80%解
    LL cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int x = i; x <= n; x++){
                for(int y = j; y <= m; y++){
                    LL res = a[x][y] - a[i-1][y] - a[x][j-1] + a[i-1][j-1];
                    if(res <= k) cnt++;
                }
            }
        }
    }

    cout << cnt << endl;
*/

    LL cnt = 0;
    for(int x1 = 1; x1 <= n; x1++){
        for(int x2 = x1; x2 <= n; x2++){
            memset(sum_col, 0, sizeof sum_col);
            for(int i = 1; i <= m; i++){
                sum_col[i] = a[x2][i] - a[x2][i-1] - a[x1-1][i] + a[x1-1][i-1];
            }

            int l = 1;
            LL sum = 0;
            for(int r = 1; r <= m; r++){
                sum += sum_col[r];
                while(sum > k){
                    sum -= sum_col[l];
                    l++;
                }
                cnt += r - l + 1;   //对于给定r，有多少l是合法的 
            }

        }
    }
    cout << cnt << endl;

    return 0;
}