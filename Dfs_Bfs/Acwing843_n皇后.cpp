#include <iostream>

using namespace std;

const int N = 20;
char g[N][N];
int n;
bool col[N],dg[N],udg[N];

/*y纵坐标，为层数，递归从最底下一层往上*/
/*x横坐标，为列数*/
/*col[]用来判断那一列还能不能放*/
/*dg[]判断对角线能不能放，udg[]判断反对角线能不能放*/
/*dg[n+x-y]，udg[x+y]为对角线索引，对角线上横纵坐标之差为定值，反对角线上，横纵坐标对角线之和为定值，可以通过y=x+b来便于理解，将横纵坐标的关系映射到截距b上*/
void dfs(int y){
    if(y == n){
        for(int i=0;i<n;i++) puts(g[i]);
        puts("");
        return;
    }
    for(int x=0;x<n;x++){
        if(!col[x]&&!dg[n+x-y]&&!udg[x+y]){
            g[x][y]='Q';
            col[x]=dg[n+x-y]=udg[x+y]=1;
            dfs(y+1);
            col[x]=dg[n+x-y]=udg[x+y]=0;
            g[x][y]='*';
        }
    }

}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) g[i][j]='*';
    }
    dfs(0);
    return 0;
}