#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1000100 ;     //1 < n < 10^5 数组记得开大一些

int n ;
int head[N] , e[2*N] , ne[2*N] , idx = 0;   //e[2*N] 无向图记得开2*n
bool st[N] ;

int ans = N;

void add (int a , int b){
    e[idx] = b;
    ne[idx] = head[a];
    head[a] = idx;
    idx++;
}

/*计算以u为根的树的结点个数*/
int dfs(int u){
    st[u] = true;
    int sum = 1 , max_son = 0;
    for(int i = head[u] ; i != -1 ; i = ne[i]){
        int j = e[i] ;  //i只是下一个结点的索引，j才是结点的数据
        if(!st[j]){     //!st[j] 而不是 !st[i]
            int son = dfs(j); //dfs(j)
            sum += son;
            max_son = max(max_son , son);
        }
    }
    
    max_son = max(n - sum , max_son);
    
    ans = min(ans , max_son);
    
    return sum;
}

int main(){
    memset(head , -1 , sizeof(head));
    memset(st, false, sizeof(st));
    
    cin >> n ;
    for(int i = 0 ; i < n-1 ; i ++ ){
        int a , b;
        cin >> a >> b ;
        add (a , b);
        add (b , a);

    }
    
    dfs(1);
    
    cout << ans << endl;
    return 0;
}