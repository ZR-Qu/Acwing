/*  CSP201912A. 报数
    https://www.smqyoj.com/p/CSP201912A
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 666 + 10;

int a, b, c, d;

int check(int num){
    if(num % 7 == 0) return false;
    while(num > 0){
        int t = num % 10;
        if(t == 7) return false;
        num = num / 10;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    int cnt = 0, i = 1;
    while(cnt < n){
        if(!check(i)){
            if(i % 4 == 1) a++;
            else if(i % 4 == 2) b++;
            else if(i % 4 == 3) c++;
            else if(i % 4 == 0) d++;
            i++;
            continue;
        }else{
            cnt++;
            i++;
        }
    }

    cout << a << endl << b << endl << c << endl << d << endl;
    return 0;
}