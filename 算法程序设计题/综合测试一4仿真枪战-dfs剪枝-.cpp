#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 70;

int n;
int min_num;
int num[N];
int sum;
int used[N];
int ans;

bool dfs(int cnt, int curSum, int index) {
    // 拼好了
    if (cnt * ans == sum) return true;
    
    // 拼下一组
    if (curSum == ans) return dfs(cnt + 1, 0, 0);
    
    for (int i = index; i < n; i++) {
        if (used[i] || curSum + num[i] > ans) continue;
        
        if (i > 0 && !used[i - 1] && num[i] == num[i - 1]) continue;
        
        used[i] = true;
        if (dfs(cnt, curSum + num[i], i + 1)) return true;
        used[i] = false;
        
        // 重要剪枝1：如果当前组是空的，放入a[i]失败，则整个失败
        if (curSum == 0) return false;
        
        // 重要剪枝2：如果放入a[i]刚好满但后续失败，则整个失败
        if (curSum + num[i] == ans) return false;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> num[i];
        sum += num[i];
    }
    sort(num, num + n,greater<int>());
    
    min_num = max(num[0], num[n-1] + num[n-2]);

    for(ans = min_num; ans <= sum; ans++){
        memset(used, 0, sizeof used);
        if(sum % ans == 0){
            if(dfs(0,0,0)){
                cout << ans << endl;
                break;
            }
        }
    }

    return 0;
}
