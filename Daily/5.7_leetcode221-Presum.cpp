/*  221.最大正方形
    https://leetcode.cn/problems/maximal-square/description/?envType=problem-list-v2&envId=2cktkvj

    解法一：
    二维前缀和优化
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> sum(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                int val = matrix[i-1][j-1] == '1'? 1:0;
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + val;
            }
        }

        int ans = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                int mxlen = min(m-i+1, n-j+1);
                for(int len = 1; len <= mxlen; len++){
                    int x = i-1+len;
                    int y = j-1+len;

                    int f = sum[x][y] -sum[i-1][y] - sum[x][j-1] + sum[i-1][j-1];
                    if(f == len*len){
                        ans = max(ans, f);
                    }
                }
            }
        }
        return ans;
    }
};