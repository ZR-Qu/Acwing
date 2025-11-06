// 贪心思路，尽可能少的罚款，按罚款大小从大到小排序
#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int m, n;
bool st[N];

struct game{
    int t;  // 截止时间
    int w;  // 罚款

    bool operator > (const game& m ) const{
        return w > m.w;
    }
}games[N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        cin >> games[i].t;
    }
    for(int i = 0; i < n; i++){
        cin >> games[i].w;
    }

    sort(games, games+n,greater<game>());

    for(int i = 0; i < n; i++){
        int flag = 0;
        int t = games[i].t;
        int w = games[i].w;
        for(int j = t; j > 0; j--){
            if(!st[j]){
                st[j] = true;
                flag = 1;
                break;
            }
        }
        if(!flag){
            for(int j = n; j > t; j--){
                if(!st[j]){
                    st[j] = true;
                    m -= w;
                    break;
                }
            }
        }
    }

    cout << m << endl;

    return 0;
}