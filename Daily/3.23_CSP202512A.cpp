/*  
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+10;
const int M = 100+10;
const int K = 1000+10;
typedef long long LL;

struct jihe{
    LL len;
    LL b[K];
}S[M], T[M];

LL a[N];

int f(jihe s){
    int res = 0;
    for(int i = 0; i < s.len; i++){
        res = res ^ a[s.b[i]];
    }
    return res;
}

int check_right(jihe s, jihe t){
    int len1 = s.len;
    int len2 = t.len;
    if(len1 != len2) return false;
    for(int i = 0; i < len1; i++){
        if(s.b[i] != t.b[i]) return false;
    }
    return true;
}

int check_xiaoc(jihe s, jihe t){
    if(f(s) == f(t)) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> S[i].len;
        for(int j = 0; j < S[i].len; j++){
            cin >> S[i].b[j];
        }
    }
    for(int i = 0; i < m; i++){
        cin >> T[i].len;
        for(int j = 0; j < T[i].len; j++){
            cin >> T[i].b[j];
        }
    }

    for(int i = 0; i < m; i++){
        int ans1 = check_right(S[i], T[i]);
        int ans2 = check_xiaoc(S[i], T[i]);
        if(ans1 == ans2){
            cout << "correct" << endl;
        }else{
            cout << "wrong" << endl;
        }
    }
    
    return 0;
}