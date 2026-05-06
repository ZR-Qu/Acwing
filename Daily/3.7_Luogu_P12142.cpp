/*  P12142 [蓝桥杯 2025 省 A] 黑客
    https://www.luogu.com.cn/problem/P12142
*/
/*  考虑不周的样例
    1：
        3
        1 1 1
    ans: 1
    2：
        4
        1 2 10000 10000
    ans: 2
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
# define MOD 1000000007
const int N = 500000+10;

LL input, k;
LL f[N];
LL fac[N], infac[N];
LL nums[N];
int cnt = 0;

LL res = 0;

LL qmi(LL a, LL b){
    LL res = 1;
    while(b){
        if(b & 1){
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b = b >> 1;
    }
    return res % MOD;
}

LL solve(LL x){
    LL ans = fac[k];

    for(int i = 0; i < cnt; i++){
        auto t = nums[i];
        if(t != x && t!= k/x)ans = ans * (infac[f[t]]) % MOD;
        else if(t == x && t == k/x)ans = ans * (infac[f[t]-2]) % MOD;   // fix： 不周样例1
        else ans = ans * (infac[f[t]-1]) % MOD;
    }
    
    return ans;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> input;
    k = input - 2;
    for(int i = 0; i < input; i++){
        int t;
        cin >> t;
        f[t]++;
    }

    fac[0] = infac[0] = 1;
    for(int i = 1; i < N; i++){
        fac[i] = fac[i-1] * i % MOD;
        infac[i] = infac[i-1] * qmi(i,MOD-2) % MOD;
    }

    for(int i = 0; i < N; i++){ // fix：需要是N而不是k，具体见不周样例2 : k只是矩阵中数的个数和矩阵规模的约束，但矩阵中的值可以大于k，这部分漏掉了
        if(f[i]) nums[cnt++] = i;
    }    

    for(int i = 0; i < cnt; i++){
        auto x = nums[i];
        if(x > k/x) break;
        if(k % x == 0 && f[k/x]){
            if(x == k/x && f[x] < 2) continue;
            LL ans = solve(x);
            res = (res + ans) % MOD;
            if(k/x != x) res = (res + ans) % MOD;
        }
    }

    cout << res << endl;

    return 0;
}