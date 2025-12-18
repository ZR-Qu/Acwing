#include <bits/stdc++.h>

using namespace std;

const int N = 2010;
int f[N];

int n, m;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x == 1){
            int a, b;
            cin >> a >> b;
            for(int j = m; j >= 0; j--){
                for(int v = 1; v <= j; v++){
                    int w = a*v*v - b*v;
                    f[j] = max(f[j], f[j-v] + w);
                }
            }
        }else if(x == 2){
            int a, b, c;
            cin >> a >> b >> c;

            int v[20], w[20];

            int k = 1,cnt = 0;

            while(c >= k){
                cnt++;
                v[cnt] = b*k;
                w[cnt] = a*k;

                c -= k;
                k = k << 1;
            }

            if(c){
                cnt++;
                v[cnt] = b*c;
                w[cnt] = a*c;
            }

            for(int j = 1; j <= cnt; j++){
                for(int z = m; z >= v[j]; z--){
                    f[z] = max(f[z], f[z-v[j]] + w[j]);
                }
            }

        }else if(x == 3){
            int a, b;
            cin >> a >> b;
            for(int j = b; j <= m; j++){
                f[j] = max(f[j], f[j-b] + a); 
            }
        }
    }

    cout << f[m] << endl;
    return 0;
}