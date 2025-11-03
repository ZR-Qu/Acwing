#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 100010;
int n , m;

int head[N] , e[N] , ne[N] , idx = 0;

int dist[N];
queue<int> q;

bool st[N];

void add(int a , int b){
    e[idx] = b , ne[idx] = head[a] , head[a] = idx++;
}

int bfs(int u){
    q.push(u);
    st[u] = true;
    dist[u] = 0 ;

    while(q.size()){
        int t = q.front();
        q.pop();

        for(int i = head[t] ; i != -1 ; i = ne[i]){
            int j = e[i];
            if(!st[j]){
                q.push(j);
                st[j] = true ;
                dist[j] = dist[t] + 1;
            }

            if(j == n) return dist[j];
        }
    }

    return -1;
}

int main(){
    memset(head , -1 ,sizeof head);
    memset(dist , -1 ,sizeof dist);
    memset(st , false ,sizeof st);

    cin >> n >> m;
    for(int i = 0 ; i < m ; i ++){
        int a , b;
        cin >> a >> b ;
        add (a,b);
    }
    cout << bfs(1) << endl;
    return 0;
}
