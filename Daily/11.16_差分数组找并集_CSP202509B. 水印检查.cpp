#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int csp[5][9] = {
    {1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,1,0,1},
    {1,0,0,1,1,1,1,1,0},
    {1,0,0,0,0,1,1,0,0},
    {1,1,1,1,1,1,1,0,0}
};


int main(){
    ios::sync_with_stdio(0); cin.tie(); cout.tie(0);
    int n,l;
    cin >> n >> l;

    vector<vector<int>> a(n, vector<int>(n));
    vector<int> diff(l+2,0);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i <= n-5; i++){
        for(int j = 0; j <= n-9; j++){
            int max_k = l;
            int min_k = 0;
            for(int x = 0; x < 5; x++){
                for(int y = 0; y < 9; y++){
                    if(csp[x][y] == 1)max_k = min(max_k, a[i+x][j+y]);
                    if(csp[x][y] == 0)min_k = max(min_k, a[i+x][j+y]+1);
                }
            }
            if(min_k <= max_k){
                diff[min_k]++;
                diff[max_k+1]--;
            }
        }
    }

    for(int i = 1; i < l; i++){
        diff[i] += diff[i-1];
    }
    
    for(int t = 0; t < l; t++){
        if(diff[t]){
            cout << t << endl;
        }
    }

    return 0;
}