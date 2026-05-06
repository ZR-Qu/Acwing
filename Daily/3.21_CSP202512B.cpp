/*   #CSP202512B. 数字变换
    https://www.smqyoj.com/p/CSP202512B
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 5e5+10;
const int M = 1e3+10;
int n, m;
int F[522]; // 512 + 10
int inv[522];
int k[M];   
LL input[N];

int f(int x,int ki){
    LL t = x*x + ki*ki;
    t = t % 8;
    t = t ^ ki;
    return t;
}

int g(int x, int ki){
    int a = (x & 0b111000000) >> 6;
    int b = (x & 0b000111000) >> 3;
    int c = (x & 0b000000111);

    int aa = b << 6;
    int bb = (c ^ f(b,ki)) << 3;
    int cc = a ^ f(c,ki);
    int t = aa | bb | cc;
    return t;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> k[i];
    }
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }

    for(int x = 0; x < 512; x++){
        F[x] = x;
        for(int i = 0; i < m; i++){
            F[x] = g(F[x], k[i]);
        }
    }

    for(int x = 0; x < 512; x++){
        inv[F[x]] = x;
    }

    for(int i = 0; i < n; i++){
        cout << inv[input[i]] << ' ';
    }

    return 0;
}