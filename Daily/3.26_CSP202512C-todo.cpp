/*  #CSP202512C. 图片解码
    https://www.smqyoj.com/p/CSP202512C
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 400+10;
const int M = 5e4+10;
typedef pair<int, int> PII;

int Z;
char A[N][N];
int klen;

struct op{
    int type;
    int a,b,c,d,e;
}op[M];

PII switch_plot(int x, int y, int d){

}

void solve1(struct op op1){
    int u = op1.a, v = op1.b, l = op1.c, d = op1.d, r = op1.e;

    int rot = 1;

    for(int i = 0; i < l; i++){
        for(int j = 0; j < l; j++){
            auto[x, y] = switch_plot(u+i, v+j, r);
        }
    }

}

void solve2(struct op op2){
    int u = op2.a, d = op2.b, l = op2.c, r = op2.d, o = op2.e;
    if(o == 1){
        for(; d >= u; d--){
            for(int j = l; j <= r; j++){
                swap(A[u][j], A[d][j]);
            }
            u++;
        }
        
    }else if(o == -1){
        for(; r >= l; r--){
            for(int i = u; i <= d; i++){
                swap(A[i][l], A[i][r]);
            }
            l++;
        }
    }
    return;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> Z;
    for(int i = 1; i <= Z; i++){
        for(int j = 1; j <=Z; j++){
            cin >> A[i][j];
        }
    }
    cin >> klen;
    int K[klen];
    for(int i = 0; i < klen; i++){
        cin >> K[i];
    }

    int idx = 0;
    int t = K[idx++];

    for(int i = t; i > 0; i--){
        op[i].type = K[idx++];
        op[i].a = K[idx++];    
        op[i].b = K[idx++];    
        op[i].c = K[idx++];    
        op[i].d = K[idx++];   
        op[i].e = K[idx++];    
    }

    for(int i = 1; i <= t; i++){
        if(op[i].type == 1){
            solve1(op[i]);
        }else if(op[i].type == 2){
            solve2(op[i]);
        }
    }

    int n = 0, m = 0;
    for(int i = 1; A[i][1] != '?' && i <= Z; i++){
        if(A[i][1] != '?') n++;
    }
    for(int j = 1; A[1][j] != '?' && j <= Z; j++){
        if( A[1][j] != '?' )m++;
    }

    cout << n  << ' ' << m << endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << A[i][j];
        }
        cout << endl;
    }

    return 0;
}