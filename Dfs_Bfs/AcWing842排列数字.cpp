#include <iostream>

using namespace std;

const int N =10;

int n;
int list[N];
bool used[N];

void dfs(int u){
    if(u == n){
        for(int i=0;i<n;i++){
            printf("%d ",list[i]);
        }
        puts("");
        return;
    }
    for(int i = 1;i <= n;i++){  //i<=n而不是i<u
        if(used[i] == false){
            list[u] = i;
            used[i] = true;
            dfs(u+1);
            used[i] = false;
        }
    }
}

int main(){
    cin>>n;
    dfs(0);
    return 0;
}