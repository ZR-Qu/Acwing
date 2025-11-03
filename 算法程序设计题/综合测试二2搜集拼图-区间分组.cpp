#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 200010;
LL n, R;

LL ans = 1;

struct range{
    double l,r;
    bool operator < (const range &w) const{
        return r < w.r;
    }
}range[N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> R;

    for(int i = 0; i < n; i++){
        LL x, y;
        cin >> x >> y;
        double delta = sqrt(R*R - y*y);
        range[i].l = x - delta;
        range[i].r = x + delta; 
    }

    sort(range, range + n);

    double lastdot = range[0].r;
    for(int i = 1; i < n; i++){
        if(lastdot < range[i].l){
            ans++;
            lastdot = floor(range[i].r); //看题，机器人只能去整数坐标
        }
    }
    cout << ans << endl;
    return 0;
}