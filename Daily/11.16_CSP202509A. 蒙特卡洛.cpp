#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(); cout.tie(0);
    int n, a, m = 0;
    double pi = 0;
    cin >> n >> a;
    double x, y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        if( x*x + y*y <= a*a){
            m++;
        }
    }
    pi =(double)4 * m / n;
    cout << pi << endl;
    return 0;
}