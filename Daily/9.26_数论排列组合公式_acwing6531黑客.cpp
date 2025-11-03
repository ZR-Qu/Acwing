#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define MOD 1000000007
const LL N = 5e5 + 10;
LL nm;
LL factor[N];
LL infactor[N];

vector<LL> a;
LL freq[N];

LL base;

LL ans;

LL qmi(LL a, LL b, LL p){
    LL res = 1;
    while(b){
        if(b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res % p;
}

LL solve(LL x){
    //处理方式二_优化：for(auto t : a) res = res * infactor[freq[t]] % MOD; 在主函数中提前处理，避免多次for
    LL res = base;
    LL y = nm/x;
    if(freq[y] == 0) return 0;

    if(x == y) {
        if(freq[x] < 2) return 0;
        res = res * freq[x] % MOD * (freq[x]-1) % MOD;
    } else {
        res = res * freq[x] % MOD * freq[y] % MOD;
        //res = res * 2 % MOD;
    }
    return res;
}

//处理方式一：
LL solve_1(LL x){
    LL res = factor[nm];
    LL y = nm/x;

    if(freq[y] == 0) return 0; //行满足，但是没有对应的列，没法形成矩阵的跳过

    //处理方式二：先都除了再乘回去
    for(auto t : a){
        if(t == x && t == y) res = res * infactor[freq[t] - 2] % MOD;
        else if(t == x || t == y) res = res * infactor[freq[t] - 1] % MOD;
        else res = res * infactor[freq[t]] % MOD;
    }
    return res;
}

LL solve_2(LL x){
    LL res = factor[nm];
    LL y = nm/x;

    if(freq[y] == 0) return 0; //行满足，但是没有对应的列，没法形成矩阵的跳过


    LL res = factor[nm];
    LL y = nm/x;
    for(auto t : a){
        res = res * infactor[freq[t]] % MOD;

        if(t == x && t == y) res = res * freq[t] % MOD * (freq[t] - 1) % MOD;
        else if(t == x || t == y)  res = res * freq[t] % MOD;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    LL k;
    cin >> k;
    nm = k - 2;

    //预处理阶乘
    factor[0] = infactor[0] = 1;
    for(int i = 1; i <= k; i++){
        factor[i] = factor[i-1] * i % MOD;
        infactor[i] = infactor[i-1] * qmi(i,MOD - 2,MOD) % MOD;
    }

    //输入
    for(int i = 0; i < k; i++){
        LL t;
        cin >> t;
        if(!freq[t]) a.push_back(t);
        freq[t]++;
    }
    sort(a.begin(), a.end());


    //处理
    base = factor[nm];
    for(auto t:a) base = base * infactor[freq[t]] % MOD;

    for(auto t:a){ //还可以优化只遍历一般（n<=m的部分，剩下部分同理*2即可）
        if(nm % t == 0){
            LL y = nm/t;
            if(freq[y]) ans = (ans + solve(t)) % MOD;   //行满足，但是没有对应的列，没法形成矩阵的跳过
        }
    }

    cout << ans << endl;

    return 0;
}