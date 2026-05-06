/*  P13887 [蓝桥杯 2023 省 Python A] 三国游戏
    https://www.luogu.com.cn/problem/P13887
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e5+10;

LL n;
LL a[N], b[N], c[N];
LL aa[N], bb[N],cc[N];
LL PreA[N], PreB[N], PreC[N];
LL res = -1, resA = 0, resB = 0, resC = 0;

bool compare(int a, int b){return a > b;}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){cin >> a[i];}
    for(int i = 0; i < n; i++){cin >> b[i];}
    for(int i = 0; i < n; i++){cin >> c[i];}

    for(int i = 0; i < n; i++){
        LL ai = a[i], bi = b[i], ci = c[i];
        aa[i] = ai - bi - ci;
        bb[i] = bi - ai - ci;
        cc[i] = ci - ai - bi;
    }

    sort(aa, aa+n, greater<int>());
    sort(bb, bb+n, [](int a, int b){return a > b;});
    sort(cc, cc+n, compare);

    PreA[0] = aa[0], PreB[0] = bb[0]; PreC[0] = cc[0];
    
    for(int i = 1; i < n; i++){
        PreA[i] = PreA[i-1] + aa[i];
        PreB[i] = PreB[i-1] + bb[i];
        PreC[i] = PreC[i-1] + cc[i];
    }

    for(int i = 0; PreA[i] > 0; i++){resA++;}
    for(int i = 0; PreB[i] > 0; i++){resB++;}
    for(int i = 0; PreC[i] > 0; i++){resC++;}

    
    res = max(max(resA, resB), resC);

    if(res != 0) cout << res << endl;
    else cout << -1 << endl;

    return 0;
}