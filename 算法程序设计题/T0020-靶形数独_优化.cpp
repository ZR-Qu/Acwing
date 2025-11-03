// 优化2：优先填可填方案少的空

//还可以进行的优化（未完成）
// 优化1：位运算
// 优化3：优先填权重高的空
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
int visited[60];

int get_bestchoice(){
    int bestindex = -1, minchoice = 10;
    for (int i = 0; i < (int)blank.size(); i++) {
        int x = blank[i].first, y = blank[i].second;
        if (visited[i]) continue;
        int cnt = 0;
        for (int v = 1; v <= 9; v++) {
            if (!used_row[x][v] && !used_col[y][v] && !used_block[3*(x/3)+ y/3][v]) //3*(x/3)+ y/3 得到块数索引，具体可以自己推一下，类似二维数组转一维
                cnt++;
        }
        if (cnt < minchoice) {
            minchoice = cnt;
            bestindex = i;
        }
    }
    return bestindex;
}

void dfs(int step,int res){
    if(step == (int)blank.size()){
        ans = max(ans, res);
        return;    
    }

    int index = get_bestchoice();
    if(index == -1) return;

    auto t = blank[index];

    int x = t.first, y = t.second;

    for(int i = 1; i <= 9; i++){
        if(!used_row[x][i] && !used_col[y][i] && !used_block[3*(x/3)+ y/3][i]){
            used_row[x][i] = used_col[y][i] = used_block[3*(x/3)+ y/3][i] = true;
            visited[index] = true;
            dfs(step + 1,res + i*w[x][y]);
            used_row[x][i] = used_col[y][i] = used_block[3*(x/3)+ y/3][i] = false;
            visited[index] = false;
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