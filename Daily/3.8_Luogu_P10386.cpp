/*  P10386 [蓝桥杯 2024 省 A] 五子棋对弈
    https://www.luogu.com.cn/problem/P10386
*/
#include <bits/stdc++.h>
using namespace std;
// #define white 1
// #define black 0

const int N = 10;
int g[5][5];
int cnt = 0;

int check(){
    int sum = 0;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            sum += g[i][j];
        }
    }
    if(sum != 13) return false;

    for(int i = 0; i < 5; i++){
        sum = 0;
        for(int j = 0; j < 5; j++){
            sum += g[i][j];
        }
        if(sum == 0 || sum == 5) return false;
    }

    for(int j = 0; j < 5; j++){
        sum = 0;
        for(int i = 0; i < 5; i++){
            sum += g[i][j];
        }
        if(sum == 0 || sum == 5) return false;
    }

    sum = 0;
    for(int i = 0; i < 5; i++){
        sum += g[i][i];
    }
    if(sum == 0 || sum == 5) return false;

    sum = 0;
    for(int i = 0; i < 5; i++){
        sum += g[i][4-i];
    }
    if(sum == 0 || sum == 5) return false;

    return true;
}

void dfs(int step, int white){
    if(white > 13) return;
    if(step - white > 12) return;

    if(step == 25){
        if(check())cnt++;
        return;
    }
    g[step/5][step%5] = 1;
    dfs(step+1, white+1);

    g[step/5][step%5] = 0;
    dfs(step+1, white);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    dfs(0,0);
    cout << cnt << endl;
    return 0;
}