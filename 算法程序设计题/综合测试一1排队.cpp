#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

void solve(LL x, LL y, LL a, LL b, LL c){
    LL ans1 = x * y;
    LL ans2 = a + b;
    LL ans = max(ans1, ans2) + c;
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    while(n--){
        LL x,y,a,b,c;
        cin >> x >> y >> a >> b >> c;
        solve(x,y,a,b,c);
    }
    return 0;
}
