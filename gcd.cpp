#include <iostream>

using namespace std;
typedef unsigned long long LL;

LL gcd(LL a, LL b){
    return b? gcd(b, a%b) : a;
}

int main(){
    LL a,b;

    cin >> a >> b;

    LL res = gcd(a, b);

    cout << res << endl;

    return 0;
}