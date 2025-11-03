#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 1e6+10;

LL h[N];
LL t[N];


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    LL n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    
    LL res = 0;
    t[n] = h[n];
    for(int i = n-1; i >=1; i--){
        t[i] = max(h[i], t[i+1] + 1);
        res = max(res, t[i]);
    }
    cout << res << endl;
    return 0;
}
