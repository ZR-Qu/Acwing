#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 110;
typedef pair<int, int> PII; // 数据为一对一对的
int m, n;                   // 迷宫大小
int g[N][N];                // 迷宫地图
int d[N][N];                // 距离表
queue<PII> q;               // 队列

int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1}; // 分别为上下左右偏移向量

/*bfs的逻辑：
1.得到队首数据t
2.while循环判断,符合要求就添加到队尾
3.t=t->next*/
int bfs()
{
    if (g[0][0] == 1 || g[m - 1][n - 1] == 1)
        return -1; // 如果起点终点是墙就报错
    q.push({0, 0});
    while (q.size())
    { // 是q.size或者!q.empty()
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        { // 判断上下左右都能不能走
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            if (x >= 0 && x < m && y >= 0 && y < n && g[x][y] == 0 && d[x][y] == -1)
            {
                q.push({x, y});
                /*更新到（0，0）的距离*/
                d[x][y] = d[t.first][t.second] + 1; // 是d[t.first][t.second]而不是g[t.first][t.second]
            }
        }
    }
    return d[m - 1][n - 1];
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
            d[i][j] = -1;
        }
    d[0][0] = 0;
    cout << bfs() << endl;
    return 0;
}