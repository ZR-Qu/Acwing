#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

int w[9][9] = {
    {6,6,6,6,6,6,6,6,6},
    {6,7,7,7,7,7,7,7,6},
    {6,7,8,8,8,8,8,7,6},
    {6,7,8,9,9,9,8,7,6},
    {6,7,8,9,10,9,8,7,6},
    {6,7,8,9,9,9,8,7,6},
    {6,7,8,8,8,8,8,7,6},
    {6,7,7,7,7,7,7,7,6},
    {6,6,6,6,6,6,6,6,6}
};

int g[9][9];
int ans = -1;
int used_row[9][10], used_col[9][10], used_block[9][10]; // used[i][j] 第i行/列/块的数字j是否用过
vector<PII> blank;

void dfs(int index,int res){
    if(index == (int)blank.size()){
        ans = max(ans, res);
        return;    
    }

    auto t = blank[index];

    int x = t.first, y = t.second;

    for(int i = 1; i <= 9; i++){
        if(!used_row[x][i] && !used_col[y][i] && !used_block[3*(x/3)+ y/3][i]){
            used_row[x][i] = used_col[y][i] = used_block[3*(x/3)+ y/3][i] = true;
            dfs(index + 1,res + i*w[x][y]);
            used_row[x][i] = used_col[y][i] = used_block[3*(x/3)+ y/3][i] = false;
        }
    }

}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int res = 0;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >>g[i][j];
            if(g[i][j]){
                if(used_row[i][g[i][j]] ||used_col[j][g[i][j]] || used_block[3*(i/3) + j/3][g[i][j]]){
                    cout << -1 << endl;
                    return 0;
                }
                used_row[i][g[i][j]] = used_col[j][g[i][j]] = used_block[3*(i/3) + j/3][g[i][j]] = true;
                res += g[i][j]*w[i][j];
            }
            else blank.push_back({i, j});
        }
    }

    dfs(0,res);

    if(ans == -1){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }

    return 0;
}