#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>    //构建哈希表

using namespace std;

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1}; // 分别为上下左右偏移向量

int bfs(string start){
    queue<string> q;
    q.push(start);  //首先把传入的初始数据储存在队列中

    unordered_map<string, int> dist;
    string end = "12345678x";

    dist[start] = 0;

    while (q.size()){
        auto t = q.front();

        q.pop();
        int distance = dist[t];

        if (t == end) return dist[t];   //返回dist[t]，而不是dist[start]

        for (int i = 0; i < 4; i++){
            /*提前把坐标用变量表示出来*/
            int x_pos = t.find('x');            //x的一维位置
            int a = x_pos / 3, b = x_pos % 3;   //x的二维坐标
            int c = a + dx[i] , d = b + dy[i];  //与x交换的数的二维坐标
            int next_pos = 3 *c + d;            //与x交换的数的一维位置
            
            if (c >= 0 && c < 3 && d >=0 && d < 3){
                swap(t[x_pos],t[next_pos]);

                if(!dist.count(t)){     //count()用于计算这个值出现次数，常用于map和hash，count==0说明没走过，可以走
                    q.push(t);
                    dist[t]= distance + 1;
                }

                swap(t[x_pos],t[next_pos]);
            }
        }
    }
    return -1;
}

int main(){
    string start;
    char c;
    for(int i=0;i<9;i++){
        cin >> c;
        start += c;
    }
    cout << bfs(start) << endl;
    return 0;
}