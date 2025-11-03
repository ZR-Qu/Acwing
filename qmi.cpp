#include <iostream>

using namespace std;

typedef long long LL;

int qmi(int a, int b, int p){
    int res = 1;
    while(b){
        if(b & 1)res = (LL) res * a % p;    //别漏if(b & 1)
        a = (LL) a * a % p;
        b = b >> 1;
    }
    return res % p; //别漏%p
}

int main(){
    int a, b, p;
    cin >> a >> b >> p;
    cout << qmi(a, b, p) << endl;
}