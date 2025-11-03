#include <iostream>
using namespace std;

const int N = 1e6 + 10;
bool st[N];
int n;

int solve(int n){
    int cnt = 0;

    int prime[n];
    for(int i = 2; i <= n; i++){
        if(!st[i]) prime[cnt++] =i;
        for(int j = 0 ; prime[j] * i <= n; j++){
            st[prime[j] * i] = true;
            if(i%prime[j] == 0) break;  // 记得是 ==0 才是整除判断，否则是不整除时停止
        }
    }
    return cnt;
}

int main(){
    scanf("%d", &n);
    int ans = solve(n);
    printf("%d", ans);
    return 0;
}

/*
此时i = k * primes[j]（k≥1）
对于更大的质数primes[j+1]，primes[j+1] * i = primes[j+1] * k * primes[j]
这个数应该被primes[j]筛掉（因为primes[j]是更小的质因数），所以可以跳过
*/
/*
每个合数只被它的最小质因数筛掉一次
例如：数字12只会被2×6筛掉（当i=6时），而不会被3×4筛掉
因为当i=4时，遇到primes[j]=2（2是4的因数）就会break，不会处理primes[j]=3的情况
*/
