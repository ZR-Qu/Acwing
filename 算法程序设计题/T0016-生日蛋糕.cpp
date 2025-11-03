#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int Max = 30;

int n, m;

int minV[Max], minS[Max];

int ans = INF;

// int V(int r,int h){
//     return r*r*h;
// }

// int S(int r,int h){
//     return 2*r*h;
// }

void dfs(int M, int remainV, int curS, int r, int h){    //剩余层数， 剩余体积， 目前表面积， 上层的r、h
    if(M == 0){
        if(remainV == 0) ans = min(ans, curS);
        return;
    }

    //if(remainV < 0) return;
    //if(curS >= ans) return;
    if(remainV < minV[M]) return;
    if(curS + minS[M] >= ans) return;

    // 剪枝3：关键剪枝 - 体积与表面积关系 
    // 动态下界剪枝 对于给定的体积V和半径R，侧面积公式 2V/R， R取上一层的 时，侧面积最小
    if (curS + 2 * remainV / r >= ans) return;  //想不到啊wc！@！@！@！比 if(curS + minS[M] >= ans) return;剪枝力度更大 2 * remainV / r --> 假设当前剩余体积都做成半径为 r 的最小圆柱

    for(int i = r-1; i >= M; i--){  //半径至少要比剩余层数大（剪枝）
        int maxh = min((int)remainV /(i*i),h-1);

        if(maxh < M) continue;  //最大的可能高度范围缩小，继续剪枝

        for(int j = maxh; j >= M; j--){ //高度也是至少要比剩余层数大（剪枝）
            int vi = i*i*j;
            int si = 2*i*j;

            if(M == m) si += i*i;

            if(vi <= remainV && ans > curS+si) dfs(M-1, remainV-vi, curS+si, i, j);
        }
    }

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    //预处理来加速
    for(int i = 1; i <=m; i++){
        minV[i] = minV[i-1] + i*i*i;
        minS[i] = minS[i-1] + 2*i*i;
    }

    dfs(m, n, 0, n + 1, n + 1);

    if (ans == INF) cout << 0 << endl;
    else cout << ans << endl;

    return 0;
}