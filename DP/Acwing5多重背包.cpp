#include <iostream>
#include <algorithm>

using namespace std;

const int N = 11110;    // N >= n * lgs 数组要开大
int v[N] , w[N];
int f[N];

int main(){
    int n , V;
    cin >> n >> V;

    int cnt = 1 ;   //计数要在循环处理的外面

    for(int i = 1 ; i <= n ; i ++){
        int a , b , s;
        cin >> a >> b >> s;
        
        int k = 1;  //每次二进制分解要重置 ， k要在循环内
        
        while(s >= k){
            v[cnt] = a * k;
            w[cnt] = b * k ;

            s -= k;
            k = k * 2;
            cnt ++;
        }
        if(s > 0){
            v[cnt] = a * s;
            w[cnt] = b * s;
            cnt ++;
        }
    }

    for(int i = 1 ; i <= cnt ; i++)
    
        for(int j = V ; j >= v[i] ; j --)   
            f[j] = max(f[j] , f[j-v[i]] + w[i]);

    cout << f[V] << endl;
    return 0;
}