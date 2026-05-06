/*  P12143 [蓝桥杯 2025 省 A] 好串的数目
    https://www.luogu.com.cn/problem/P12143
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e5+10;

LL pos[N];
string s;
LL res;
LL lens[N];

LL cal(LL len){
    LL t = (len+1) * len / 2;
    return t;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> s;

    int t = s[0];
    int cnt = 0;
    for(int i = 1; i < int(s.size()); i++){
        if(s[i] == t+1 || s[i] == t){
            t = s[i];
        }
        else{
            pos[cnt++] = i-1;
            t = s[i];
        }
    }
    
    if(cnt == 0){
        res = cal(int(s.size()));
    }else{
        lens[0] = pos[0] - 0 + 1;
        for(int i = 1; i < cnt; i++){
            lens[i] = pos[i] - pos[i-1];
        }

        lens[cnt] = s.size()-1 - pos[cnt-1];

        for(int i = 0; i <= cnt; i++){
            res += cal(lens[i]);
        }

        for(int i = 0; i < cnt; i++){
            res += lens[i] * lens[i+1];
        }
    }

    cout << res << endl;
    return 0;
}