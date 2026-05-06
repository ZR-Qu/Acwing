/*  P12144 [蓝桥杯 2025 省 A] 地雷阵
    https://www.luogu.com.cn/problem/P12144
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const double PI = acos(-1.0);

int n;

struct range{
    double l;
    double r;

    bool operator < (const range &w) const{
        return l < w.l;
    }
}ranges[N];

double merge(){
    double sum = 0;
    double st = ranges[0].l;
    double ed = ranges[0].r;
    sum += ed - st;

    for(int i = 1; i < n; i++){
        double l = ranges[i].l;
        double r = ranges[i].r;
        if(st <= l && r <= ed) continue;
        else if(l <= ed && r >= ed){
            st = ed;
            ed = r;
            sum += ed - st;
        }else if(l >= ed){
            st = l;
            ed = r;
            sum += ed - st;
        }
    }
    return sum;
}

int main(){
    // ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;

        double d, alpha, theta, sin_theta;
        d = sqrt(a*a+b*b);
        alpha = atan2(b,a);
        sin_theta = c/d;
        theta = asin(sin_theta);

        double l = alpha - theta;
        double r = alpha + theta;
        ranges[i] = {l, r};
    }

    sort(ranges, ranges+n);

    double sum = merge();

    double res = ((PI/2) - sum) / (PI/2);

    printf("%.3f\n", res);
    // cout << fixed << setprecision(3) << res << endl;

    return 0;
}