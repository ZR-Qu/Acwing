#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int v[N] , w[N];
int f[N][N];

int main(){
    int n , V;
    cin >> n >> V;
    for(int i = 1 ; i <= n ; i ++) cin >> v[i] >> w[i];

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= V ; j++){
            if(v[i] <= j){  //v[i] <= j , 才对，v[i]才是物品大小，w[i]是价值 ；j才是当前背包大小，不是V
                f[i][j] = max(f[i-1][j] , f[i-1][j-v[i]] + w[i]);
            }else{
                f[i][j] = f[i-1][j];
            }
        }
    }

    cout << f[n][V] << endl;
    return 0;
}