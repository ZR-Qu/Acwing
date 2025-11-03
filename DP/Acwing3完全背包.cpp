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
    /*完全背包:每个物品可以抓无穷多
    可以假设每个物品抓k个
    1. 可以观察到
    f[i][j] =       max(f[i-1][j] , f[i-1][j - 1 * v[i]] + w[i] , f[i-1][j - 2 * v[i]] + 2 * w[i] , f[i-1][j - 3 * v[i]] + 3 * w[i] , ……)
    f[i][j-v[i]]=   max(            f[i-1][j - 1 * v[i]]        , f[i-1][j - 2 * v[i]] + w[i]     , f[i-1][j - 3 * v[i]] + 2 * w[i] , ……)
    2.所以 f[i][j] = max(f[i-1][j] , f[i][j - v[i]] + w[i])
    3.转化为一维数组
    */
    /*二维数组优化为一维数组，因为对于每次j的更新，只需用到之前i-1时的j或者j-v[i]，不会用到后面的值，因此对于i的更新，只需用一个数组，直接覆盖就行了*/
        for(int j = v[i] ; j <= V ; j ++)   //滚动数组，使得f[j-v[i]]实际上是i层的值，需要先得到f[j-v[i]]，即f[i][j-v[i]]，因此为从小到大遍历
            f[j] = max(f[j] , f[j-v[i]] + w[i]);

    cout << f[V] << endl;
    return 0;
}