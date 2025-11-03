#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
typedef long long LL;

LL n, k;
LL T;
LL a[N];
LL sum, sum2; //存前缀和
LL ans = -1;

bool check(int x){
    if (k <= 0) return false;

    LL b[N];
    for(LL i = 1; i <= x; i++) b[i] = a[i];
    sort(b + 1, b + 1 + x);

    sum = sum2 = 0;
    for(LL i = 1; i <= k; i++ ){
        sum += b[i];
        sum2 += b[i] * b[i];
    }
    double res = (double)sum2 /k - (double)sum * sum / (k*k);
    if(res <= T) return true;

    for(LL i = k+1; i <= x; i++){
        sum = sum - b[i - k] + b[i];
        sum2 = sum2 - b[i - k]*b[i - k] + b[i]*b[i];
        res = (double)sum2 /k - (double)sum * sum / (k*k);
        if(res <= T) return true;
    }
    return false;
}


int main(){
    cin >> n >> k >> T;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }

    if(!check(n)){
        cout<<-1;
        return 0;
    }

    LL l = k, r = n;
    while(l < r){
        LL mid = (l + r) >>1;
        if(check(mid)){
            r = mid;
            ans = mid;
        }else{
            l = mid + 1;
        }
    }

    cout << l << endl;

    return 0;
}