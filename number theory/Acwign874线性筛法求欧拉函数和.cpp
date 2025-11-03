#include <iostream>

using namespace std;

typedef long long LL;

const int N = 1e6 + 10;
int n;
int primes[N];
bool st[N];
int phi[N];

void solve(int n){
    int cnt = 0;
    phi[0] = phi[1] = 1;
    for(int i = 2; i <= n; i++){
        if(!st[i]){
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; i * primes[j] <= n; j++){
            st[i * primes[j]] = true;
            if(i % primes[j] == 0){
                phi[i * primes[j]] = phi[i]*primes[j];
                break;
            }
            phi[i * primes[j]] = phi[i]*(primes[j] - 1);
        }
    }

    LL res = 0;
    for(int i = 1; i <=n; i++){
        res = res + phi[i];
    }
    cout << res;
    return;
}

int main(){
    cin >> n;
    solve(n);
    return 0;
}