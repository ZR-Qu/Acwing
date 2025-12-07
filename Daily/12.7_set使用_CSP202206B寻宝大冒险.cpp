#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 50+10;
int ans;

int n, L, S;
int g[N][N];

set<PII> tree;

bool solve(int x, int y){
    for(int i = 0; i <= S; i++){
        for(int j = 0; j <= S; j++){
            if(g[i][j] == 1){
                if(!tree.count({x+i, y+j})){
                     return false;
                }
            }else{
                if(tree.count({x+i, y+j})){
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> L >> S;
    while(n--){
        int x, y;
        cin >> x >> y;
        tree.insert({x, y});
    }
    for(int i = S; i >= 0; i--){
        for(int j = 0; j <= S; j++){
            cin >> g[i][j];
        }
    }

    for(auto t: tree){
        int x = t.first;
        int y = t.second;
        if(x+S <= L && y+S <= L){
            bool flag = solve(x,y);
            if(flag == true) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}