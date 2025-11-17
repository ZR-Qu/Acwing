#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTime(vector<int>& time, int m) {
        int T = 0;
        for(auto it: time) T+=it;
        int l = 0, r = T;
        while(l < r){
            int mid = l + r >> 1;
            if(check(mid,time,m)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
private:
    bool check(int t, vector<int>& time, int m){
        int cnt = 0;//已经用掉的天数
        int mx = 0;
        int sum = 0;
        for(int i = 0; i < time.size(); i++){
            sum += time[i];
            mx = max(mx, time[i]);
            if(sum - mx > t){
                i--;
                cnt++;
                mx = 0;
                sum = 0;
            }
            if(cnt >= m) return false;
        }
        if(sum - mx > t) return false;
        return true;
    }
};