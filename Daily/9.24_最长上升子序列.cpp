#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 1010;
LL n,ans;
LL a[N];
LL f[N]; //状态表示：f[i]表示以a[i]结尾的最长子序列的长度

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < N; i++) f[i] = 1;//初始最短就是1，每一个都可能作为f[j],都要初始化为1，不能为0

    for(int i = 0; i < n; i++){//避免n = 1的情况，或者 i=1，初始化的时候就ans = 1；
        for(int j = 0; j < i; j++) if(a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
        ans = max(ans, f[i]);   //f[i]表示以a[i]结尾的最长子序列的长度，所以全局的要用ans存
    }

    cout << ans << endl;

}