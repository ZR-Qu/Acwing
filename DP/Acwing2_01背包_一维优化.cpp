#include <iostream>                                                                                       
#include <algorithm>

using namespace std;

const int N = 1010;
int v[N] , w[N];
int f[N];

int main(){
    int n , V;
    cin >> n >> V;
    for(int i = 1 ; i <= n ; i ++) cin >> v[i] >> w[i];

    for(int i = 1 ; i <= n ; i++)
    /*二维数组优化为一维数组，因为对于每次j的更新，只需用到之前i-1时的j或者j-v[i]，不会用到后面的值，因此对于i的更新，只需用一个数组，直接覆盖就行了*/
        for(int j = V ; j >= v[i] ; j --)   //逆序遍历，滚动数组，使得f[j-v[i]]实际上是i-1层的值，即f[i-1][j-v[i]]，不然从小到大遍历，f[j-v[i]]为f[i][j-v[i]],实际上要的是f[i-1][j-v[i]]
            f[j] = max(f[j] , f[j-v[i]] + w[i]);    // f[j-v[i]] + w[i]记得加w[i]

    cout << f[V] << endl;
    return 0;
}