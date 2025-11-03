#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+10;
char s[N], p[N];
int cnt; 
int ne[N];

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> (s+1) >> (p+1);

    ne[1] = 0;
    int m = strlen(s+1); //strlen(s + 1) 而不是 strlen(s)，因为字符串从下标1开始存储
    int n = strlen(p+1);
    for(int i = 2, j = 0; i <= n; i++){
        while(j && p[i]!=p[j+1]) j = ne[j];
        if(p[i] == p[j+1]) j++;
        ne[i] = j;
    }

    for(int i = 1, j = 0; i <= m; i++){
        while(j && s[i]!=p[j+1]) j = ne[j];
        if(s[i] == p[j+1]) j++;
        if(j == n){
            cnt++;
            j = ne[j]; //回退到部分匹配的位置，而不是0
        }
    }

    cout << cnt << endl;

    return 0;
}