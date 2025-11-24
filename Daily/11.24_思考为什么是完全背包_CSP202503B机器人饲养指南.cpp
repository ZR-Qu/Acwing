#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int f[N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;

    int a[m+1];

    a[0] = 0;
    for(int i = 1; i <= m; i++){
        cin >> a[i];
    }

    memset(f,-1e9, sizeof f);   //养成好习惯，防止负数
    f[0] = 0;

    for(int j = 0; j <= n; j++){
        for(int x = 1; x <= m; x++){    //x从1开始，x=0没错但没有意义
            if(j >= x)f[j] = max(f[j], f[j-x]+a[x]);
        }
    }

    cout << f[n] << endl;

    return 0;
}