#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+10;

int n, ans = 1;

struct range{
    int l, r;
    bool operator < (const range& a) const{
        if(r == a.r){
            return l < a.l;
        }else{
            return r < a.r;
        }
    }
}range[N];

int main(){
    ios::sync_with_stdio(0); cin.tie(); cout.tie();

    cin >> n;
    for(int i = 0; i < n; i++){
        int l,r;
        cin >> l >> r;
        range[i] = {l, r};
    }

    sort(range, range+n);

    int maxr = range[0].r;
    for(int i = 1; i < n; i++){
        int l = range[i].l;
        if(l >= maxr){
            ans++;
            maxr = range[i].r;
        }
    }

    cout << ans << endl;

    return 0;
}