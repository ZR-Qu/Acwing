/*  P16225 [蓝桥杯 2026 省 A] 量子 2048
    https://www.luogu.com.cn/problem/P16225
    
    解题思路：
    由于每个2*2的矩阵的和都是奇数，可以转换为异或和，即 \(a_{1,1} + a_{1,2} + a_{2,1} + a_{2,2}\) 是奇数且 \(a_{2,1} + a_{2,2} + a_{3,1} + a_{3,2}\) 也是奇数，于是我们知道 \(a_{1,1} + a_{1,2}\) 和 \(a_{3,1} + a_{3,2}\) 同奇偶。
    推广出来，我们发现 \(a_{i,j} + a_{i+1,j}\) 和 \(a_{i,j-2} + a_{i+1,j-2}\) 同奇偶，且 \(a_{i,j} + a_{i,j+1}\) 与 \(a_{i+2,j} + a_{i+2,j+1}\) 同奇偶
    
    即隔排隔列同奇偶
    简单来说，如果我们确定了第一行和第一列的数值，整个矩阵就被唯一确定了
    第一排自由基 2047 (填了2047后，最后一个由于奇偶校验被自动填入)
    之后填第一列，此时(1,1)被填过了，还剩2047个要填，自由基2046
    所以最后 2^(2047+2046),用qmi
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MOD 998244353

LL qmi(LL a, LL b, LL p){
    LL res = 1;
    while(b){
        if(b & 1) res = res * a % p;
        a = a * a % p;
        b = b >> 1;
    }
    return res % p;
}

int main(){
    int cnt = 2047 + 2046;
    LL ans = qmi(2,cnt, MOD);
    cout << ans << endl;
    return 0;
}