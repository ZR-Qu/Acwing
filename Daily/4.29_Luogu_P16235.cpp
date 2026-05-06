/*  P16235 [蓝桥杯 2026 省 B] 蓝桥竞技
    https://www.luogu.com.cn/problem/P16235

    Pronlem:
    1. 求和最好开LL, sum+=a[i], 由于LL，所以a[i]也要开LL
    2. "模拟贪心分队”反而错：贪心可能前面队伍填得太随意，后面剩下的职业组合不够
    3. 鸽巢原理
    4. 正确：所有的选手按照职业归类，排成一长列，依此1-num放，放慢就取余MOD num
       当连续发同一种职业的选手时，最多连续发 num 次。根本没有机会绕满一圈回到同一个队里,这就完美保证了“同队位置互斥”。
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
LL a[N];

// bool solve(int n, int num){
//     int team[num];
//     memset(team, 0, sizeof team);

//     for(int i = 0; i < n; i++){
//         int cnt = a[i];
//         for(int j = 0; j < num; j++){
//             if(team[j] < 5){
//                 team[j]++;
//                 cnt--;
//             }
//             if(cnt == 0){
//                 break;
//             }
//         }
//         if(cnt > 0) return false;
//     }
//     return true;
// }

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        LL sum = 0;
        int n;
        cin >> n;
        memset(a, 0, sizeof a);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }

        if(sum % 5 != 0){
            cout << "F" << endl;
            continue;
        }
        LL num = sum / 5;
        sort(a, a+n, greater<int>());
        if(a[0] > num){
            cout << "F" << endl;
            continue;
        }
        // if(solve(n, num)){
        //     cout << "T" << endl;
        //     continue;
        // }else{
        //     cout << "F" << endl;
        //     continue;
        // }
        cout << "T" << endl;
    }
    return 0;
}