#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510;

int n, a[N][N], f[N][N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }

    //从最后一行开始走，走到第一行，第一行的结果为答案
    for (int i = 1; i <= n; i++) f[n][i] = a[n][i];
    
    for (int i = n-1; i >= 1 ; i--) {
        for (int j = 1; j <= i; j++) {
            f[i][j] = max(f[i + 1][j + 1], f[i + 1][j]) + a[i][j];
        }
    }

    cout << f[1][1] << endl;

    return 0;
}