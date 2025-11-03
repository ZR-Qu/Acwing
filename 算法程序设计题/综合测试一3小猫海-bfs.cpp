#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int N = 1e3+10;

vector<vector<char>> g;
int n, m;

vector<vector<bool>> visited;

LL ans[26];

int dx[] = {-1,1,0,0}, dy[] = {0, 0, 1, -1};

void solve(int i, int j){
    bool tag[26] = {false};
    LL res = 0;
    queue <PII> q;
    q.push({i, j});
    visited[i][j] = true;

    while(q.size()){
        auto t = q.front();
        q.pop();
        int x = t.first, y = t.second;

        int w;
        if(g[x][y]>='0' && g[x][y] <= '9') w = g[x][y] - '0';
        else if(g[x][y]>='A' && g[x][y] <= 'Z'){
            w = 10;
            tag[(int)g[x][y] - 'A'] = true;
        }
        res += w;

        for(int i = 0; i < 4; i++){
            int xx = x + dx[i], yy = y + dy[i];
            if(xx >= 0 && xx < n && yy >= 0 && yy < m && g[xx][yy] != '.' && !visited[xx][yy]){
                q.push({xx,yy});
                visited[xx][yy] = true;
            }
        }
    }

    for(int i = 0; i < 26; i++){
        if(tag[i]) ans[i] = max(ans[i], res);
    }

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    
    g.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] != '.' && !visited[i][j]) solve(i,j);
        }
    }

    for(int i = 0; i < 26; i++){
        if(ans[i]!=0){
            cout << char('A'+ i)  << ' ' << ans[i] << endl;
        }
    }

    return 0;
}
