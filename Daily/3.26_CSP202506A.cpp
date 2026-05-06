/*  #CSP202506A. 正态分布
    https://www.smqyoj.com/p/CSP202506A

    坑点：浮点数精度问题
    解决：b为100的约数，先乘100，避免浮点数 ,或者四舍五入+取余， 或者+1e-9
*/
#include <bits/stdc++.h>
using namespace std;

void solve(double m){
    int t = 100*m + 1e-9;
    int i = 0, j = 0;
    j = t % 10 + 1 ;
    i = t /10 + 1;
    cout << i << ' ' << j << endl;
}

int main(){
    ios::sync_with_stdio(0);
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        double a, b, c;
        cin >> a >> b >> c;
        double m = (c-a) / b;
        solve(m);
    }
    return 0;
}