#include <iostream>
using namespace std;

const int N = 1e6;
int ed = 2025;
int cnt;
int p[2030];
int st[N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    for(int i = 2; i <= N; i++){
        if(!st[i]){
            p[cnt++] = i;
            if(cnt == 2025) break;
        }

        for(int j = 0; p[j]*i <= N; j++){
            st[p[j]*i] = true;
            if(i % p[j] == 0) break;
        }
    }

    cout << p[2024] << endl;

    return 0;
}