#include <iostream>

using namespace std;

const int N = 1e5+10;
const int M = 1e6+10;

char p[N];
char s[M];

int ne[M];

int main(){
    int n, m;
    cin >> n >> (p + 1) >> m >> (s + 1);
    
    /*初始化next数组*/
    ne[1] = 0;
    for(int i = 2, j = 0; i <= n; i++){
        while(j && p[i] != p[j+1]) j = ne[j];
        if(p[i] == p[j+1]) j++;
        ne[i] = j;
    }
    
    for(int i = 1, j = 0; i <= m; i++ ){ //i <= m
        while(j && s[i] != p[j+1]) j = ne[j];
        if(s[i] == p[j+1]) j++;
        if(j == n) printf("%d ", i-n); //下标从0记 i-n ; 下表从1记 i-n+1
    }
    
    
    return 0;
}