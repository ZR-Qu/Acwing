#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long LL;

const int Mod = 1e9 + 7;

unordered_map<int, int> primes;

void solve(int n){

    for(int i = 2; i <= n/i; i++){
        while(n%i == 0){
            n /= i;
            primes[i]++;
        }
    }
    if(n > 1) primes[n]++;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        solve(x);
    }

    int res = 1;
    for(auto& p : primes){
        res =(1LL) * res * (p.second + 1) % Mod;
    }
    printf("%d\n", res);

    return 0;
}