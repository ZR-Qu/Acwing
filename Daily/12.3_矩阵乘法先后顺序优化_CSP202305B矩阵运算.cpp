#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
typedef long long LL;

void matrix_mul(vector<vector<LL>> &a,vector<vector<LL>> &b, int m, int n,int k ,vector<vector<LL>> &c){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < k; j++){
            c[i][j] = 0;
            for(int z = 0; z < n; z++){
                c[i][j] += a[i][z]*b[z][j];
            }
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, d;
    cin >> n >> d;

    vector<vector<LL>> q(n,vector<LL>(d)), k(d,vector<LL>(n)), v(n,vector<LL>(d));
    vector<vector<LL>> c1(d, vector<LL>(d));
    vector<vector<LL>> c2(n, vector<LL>(d));
    int w;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < d; j++)
            cin >> q[i][j];
    
    for(int j = 0; j < n; j++)
        for(int i = 0; i < d; i++)
            cin >> k[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < d; j++)
            cin >> v[i][j];  
    
    for(int i = 0; i < n; i++){
        cin >> w;
        for(int j = 0; j < d; j++) q[i][j] = q[i][j] * w;
    }

    matrix_mul(k,v,d,n,d,c1);
    matrix_mul(q,c1,n,d,d,c2);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < d; j++){
            cout << c2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}