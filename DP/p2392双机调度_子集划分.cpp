#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 20 * 60 + 10;

int s[4];
int cost[20];
int f[N]; //求时间为N时耗时的最大值

int res;

int main(){
    for(int i = 0 ;i < 4; i++) scanf("%d", &s[i]);
    for(int i = 0; i < 4; i++){ //科目数
        int t = 0;
        for(int j = 0; j < s[i]; j++){ //题目数
            scanf("%d", &cost[j]);
            t += cost[j]; // 一道题一道题做的总时间
        }

        memset(f, 0, sizeof f);

        //每个科目内0-1背包，同时做 想让双机调度时间短，这需要左右两个子集的时间都尽量接近一题一题做的时间的一半， 所以背包上限时间一半，求时间短的子集最接近t/2的情况
        for(int j = 0; j < s[i]; j++){
            for(int k = t/2; k >= cost[j]; k--){    //是j不是i
                f[k] = max(f[k], f[k - cost[j]] + cost[j]);
            }
        }

        res += t - f[t/2];
    }

    printf("%d\n", res);
    return 0;
}