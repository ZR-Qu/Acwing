//选择尽量少的点，每个区间内至少包含一个选出的点 => 不相交选一个点 点数等价于最大不相交区间数
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int n, ans;

struct range{
    int l, r;
    bool operator< (const range& w) const{
        return r < w.r;
    }
}range[N];

int main(){
    cin >> n;
    int l, r;
    for(int i = 0; i < n; i++){
        scanf("%d%d", &l, &r);
        range[i] = {l, r};
    }
    sort(range, range + n);
    int lastdot = range[0].r;
    ans = 1;
    for(int i = 1; i < n; i++){
        if(range[i].l > lastdot){
            ans++;
            lastdot = range[i].r;
        }
    }
    
    cout << ans << endl;
    return 0;
}