#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
typedef long long LL;

LL w[N];
LL maxPre[N];
LL maxSuf[N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    LL suma[N], sumb[N];
    int n;
    cin >> n;

    memset(suma, 0, sizeof suma);
    memset(sumb, 0, sizeof sumb);

    for(int i = 0; i <= n; i++){
        cin >> suma[i];
        if(i) suma[i] += suma[i-1];
        w[i] += suma[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> sumb[i];
        sumb[i] += sumb[i-1];
        w[i] -= sumb[i];
    }

    // for(int i = 0; i <= n; i++){
    //     w[i] = suma[i] - sumb[i];
    // }

    for(int i = 0; i <= n; i++){
        maxPre[i] = w[i];
        if(i) maxPre[i] = max(maxPre[i-1], w[i]);
    }

    maxSuf[n] = w[n];
    for(int i = n-1; i >= 0; i--){
        maxSuf[i] = max(maxSuf[i+1], w[i]);
    }

    // 1 到 n 发生意外的情况，k 从 1 开始
    // 分段考虑
    // 用未出现意外时的第0-k-1站中的最高要求和第k-n站之间的最高要求 一拼，可以求出max
    // 现在出问题了，第k-n站之间出现过的最高要求还要多加上b_k;
    for(int k = 1; k <= n; k++){
        LL ans;
        if(k) ans = max(maxPre[k-1], maxSuf[k]+sumb[k]-sumb[k-1]);
        else ans = max(maxPre[k-1], maxSuf[k]+sumb[k]);
        cout << ans << " ";
    }

    return 0;
}