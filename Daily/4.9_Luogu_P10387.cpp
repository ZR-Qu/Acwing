/*  P10387 [蓝桥杯 2024 省 A] 训练士兵
    https://www.luogu.com.cn/problem/P10387
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
typedef long long LL;

LL sump;
LL res;

struct man{
    int p;
    int c;

    bool operator <(const man &w)const{
        return c < w.c;
    }
}mans[N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    LL n, s;
    cin >> n >> s;
    mans[0].p = 0; mans[0].c = 0;
    for(int i = 1; i <= n; i++){
        int p, c;
        cin >> p >> c;
        mans[i].p = p;
        mans[i].c = c;
        sump += p;
    }

    sort(mans+1, mans+n+1);

    for(int i = 1; i <= n; i++){
        LL d = mans[i].c - mans[i-1].c;
        if(sump > s){
            res += s*d;
        }else{
            res += sump*d;
        }
        sump -= mans[i].p;
    }

    cout << res << endl;
    
    return 0;
}