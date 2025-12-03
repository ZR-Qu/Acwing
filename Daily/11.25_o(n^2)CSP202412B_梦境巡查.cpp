#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int a[N], b[N];
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int j = 1; j <=n; j++){
        int ans = a[n];
        int t = b[j];
        b[j] = 0;
        for(int i = n; i > 0; i--){
            ans = max(a[i-1], ans+a[i-1]-b[i]);
        }
        cout << ans << " ";
        b[j] = t;
    }
    return 0;
}