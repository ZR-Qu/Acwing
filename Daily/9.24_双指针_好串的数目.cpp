#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

LL ans;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    int n = s.length();
    int l = 0, r, cnt = 1;

    vector<int>block;//什么都开LL最保险 vector<LL>block

    for(int r = 1; r < n; r++){
        if(!(s[r] ==s[r - 1] || s[r] == s[r - 1] + 1)){
            block.push_back(r - l);
            l = r;
        }
    }
    block.push_back(n - l);

    //分段内无断点和段内一个断点（即跨段）来分别计算，如果每次两段两段合在一起算（m+n）*(m+n+1)/2,就会导致中间的两段段内的这部分被重复计算两遍，同时两端的单独这一段又没有算到
    //段内
    for(int i = 0; i < block.size(); i++) ans += (LL)block[i] * (block[i] + 1) / 2;   //(LL)防止溢出，什么都开LL最保险

    //跨段
    for(int i = 1; i < block.size(); i++) ans += (LL)block[i-1] * block[i];

    cout << ans;

    return 0;
}