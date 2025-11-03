#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int hour, min;
    int flag = 0;
    if(d - b <0){
        min = d - b + 60;
        flag = 1;
    }else{
        min = d - b;
    }
    hour = c - a - flag;
    cout << hour <<' '<< min << endl;
    return 0;
}