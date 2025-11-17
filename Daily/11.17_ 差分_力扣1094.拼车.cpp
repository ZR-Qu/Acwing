#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1002,0);   //差分数组比边界大至少2
        for(auto t:trips){
            int num = t[0], from = t[1], to = t[2];
            diff[from] += num;
            diff[to] -= num;    //边界处理：to时已经下车，即[from, to),差分模板是[a,b]才是diff[b+1] -= c;
        }

        for(int i = 0; i < 1002; i++){  //边界处理：i从0开始，因为初始也要判断是否超载（下一句的if判断）
            if(i)diff[i] += diff[i-1];  //但是i=0不需要前缀和算
            if(diff[i] > capacity) return false;
        }

        return true;
    }
};