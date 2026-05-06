/*  739. 每日温度
    https://leetcode.cn/problems/daily-temperatures/description/?envType=problem-list-v2&envId=2cktkvj

    考点：
    找右边第一个比自己大的元素 -> 单调栈
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> ans(len);
        stack<int> st;  //存下标

        for(int i = 0; i < len; i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                int idx = st.top();
                st.pop();
                ans[idx] = i - idx;
            }
            st.push(i);
        }

        return ans;
    }
};