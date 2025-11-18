#include <bits/stdc++.h>
using namespace std;
const int N = 110;

typedef pair<int,int> PII;

int dx[] = {1,2,2,1,-1,-2,-2,-1};
int dy[] = {2,1,-1,-2,-2,-1,1,2};

int g[N][N];
int visited[N][N];

queue<PII> q;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    int a,b;
    cin >> n >> k >> a >> b;

    visited[a][b] = true;
    q.push({a,b});

    int cnt = 1,step = 0;

    while(q.size() && step < k){
        int num = q.size();
        while(num--){
            auto t = q.front();
            q.pop();
            int x = t.first, y = t.second;
            for(int i = 0; i < 8; i++){
                int xx = x + dx[i], yy = y + dy[i];
                if(!visited[xx][yy] && xx > 0 && xx <= n && yy > 0 && yy <= n){
                    visited[xx][yy] = true;
                    q.push({xx,yy});
                    cnt++;
                }
            }
        }
        step++;
    }

    cout << cnt << endl;

    return 0;
}