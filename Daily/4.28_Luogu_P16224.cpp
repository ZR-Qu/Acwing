/*  P16224 [蓝桥杯 2026 省 A] 均衡数
    https://www.luogu.com.cn/problem/P16224
*/
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;

void check(ULL x){
    ULL t = x;
    int cnt0 = 0;
    int cnt1 = 0;
    while(t){
        if((t&1) == 1){
            cnt1++;
        }else if((t&1) == 0){
            cnt0++;
        }
        t = t >> 1;
    }
    // cout << "0:" << cnt0 << endl;
    // cout << "1:" << cnt1 << endl;
}

int main(){
    ULL n = 2026202620262026;
    ULL a = 2251799847239679;
    ULL b = 1125899873288192;
    check(n);
    // cout << "a:"<< endl;
    check(a);
    // cout << "b:" << endl;
    check(b);
    if(a-n < n-b){
        cout << a << endl;
    }else{
        cout << b << endl;
    }
    return 0;
}