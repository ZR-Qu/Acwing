#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long LL;

void solve(int n){
    unordered_map<int, int> primes;
    LL fai = n; //要用long long类型，防止溢出
    
    for(int i = 2; i <= n/i; i++){
        while(n % i ==0){
            n = n / i;
            primes[i]++;
        }
    }
    if(n > 1) primes[n]++;
    
    for(auto&p: primes){
        int prime = p.first;
        fai = fai / prime * (prime - 1); //最好先除后乘，不然容易溢出
        //  fai *= (prime - 1);         
        //  fai /= prime;
    }
    cout << fai << endl;
    
    return;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        solve(x);
    }
    return 0;
}