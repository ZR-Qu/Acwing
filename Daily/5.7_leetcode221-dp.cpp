/*  221.最大正方形
    https://leetcode.cn/problems/maximal-square/description/?envType=problem-list-v2&envId=2cktkvj

    解法二：
    dp
    dp[i][j]= 以matrix[i][j]作为右下角时，能形成的最大正方形边长
    上边能撑住
    左边能撑住
    左上角那块也能撑住，取min，画图好理解
    则matrix[i][j] = 1时，dp[i][j]也能覆盖之前的，同时更大一个 +1；
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int mxlen = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int val = matrix[i][j] == '1'? 1:0;
                if(val == 1){
                    if(i == 0 || j == 0){
                        dp[i][j] = 1;
                    }else{
                        dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                    }
                    mxlen = max(mxlen, dp[i][j]);
                }
            }
        }

        return mxlen*mxlen;
    }
};