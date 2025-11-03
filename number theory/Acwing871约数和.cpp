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

    LL res = 1;
    for(auto& p : primes){
        int prime = p.first;
        int count = p.second;

        // 计算约数和 sum = (p1^0 + p1^1 + ... + p1^count1) * (p2^0 + p2^1 + ... + p2^count2) * ...
        LL t = 1;
        for(int i = 0; i < count; i++){
            t = (t * p.first + 1) % Mod;    // 秦九韶算法 t_n+1 = t_n * p + a0, 刚好多项式每一项的系数都为1
        }

        res = (res * t) % Mod;
    }
    printf("%d\n", res);

    return 0;
}