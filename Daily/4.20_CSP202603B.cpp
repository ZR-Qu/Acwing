/*  #CSP202603B. 机器人项目管理
    https://www.smqyoj.com/p/CSP202603B

    Problem:
    1. double转化 注意 (double)a/b;
    2. 背包求最大值，所以要转化问题为求减少的时间的最大值，总时间-最大值 为最后的结果

    思路：
    没必要用分数，贪心的话一定是一杯一杯的，不会半杯，可把灵活性转化为1杯1杯即可（类似多重背包那种拆开的思想）
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 20010;
const int M = 1010;

int n, m;
int idx = 0;
struct robot{
    double t;
    int v;
}robots[N];

double f[M];

double sum_t = 0;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int o, t, a, b;
        cin >> o >> t >> a >> b;
        sum_t += t;
        if(o == 0){
            double avl = (double)b / a;
            while(a--){
                idx++;
                robots[idx].t = avl;
                robots[idx].v = 1;
            }
        }else if(o == 1){
            idx++;
            robots[idx].t = b;
            robots[idx].v = a;
        }
    }

    for(int i = 1; i <= idx; i++){
        for(int j = m; j >= robots[i].v; j--){
            f[j] = max(f[j], f[j-robots[i].v] + robots[i].t);
        }
    }

    printf("%.6f", sum_t - f[m]);

    return 0;
}