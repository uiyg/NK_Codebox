#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1010;
char a[N][N];

// 定义一个结构体，用于存储当前节点的信息
typedef array<int, 5> node;
queue<node> q;
// 定义一个四维数组，用于记录每个节点是否被访问过
int vis[N][N][5][2];
// 定义四个方向，分别是上下左右
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

// 定义一个函数，用于解决迷宫问题
void solve()
{
    int n, m, ans = -1;
    cin >> n >> m;
    // 读取迷宫信息
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    // 将起点加入队列
    q.push({1, 1, 0, 0, 1});
    q.push({1, 1, 0, 1, 1});
    q.push({1, 1, 0, 2, 1});
    q.push({1, 1, 0, 3, 1});
    q.push({1, 1, 0, 4, 0});
    while (q.size())
    {
        // 取出队列中的第一个节点
        auto [x, y, dir, ban, k] = q.front();
        q.pop();
        // 判断是否越界
        if (x <= 0 || y <= 0 || x > n || y > m)
            continue;
        // 判断是否已经访问过
        if (vis[x][y][ban][k])
            continue;
        // 判断是否遇到障碍物
        if (a[x][y] == 'X' && !k)
            continue;
        // 标记为已访问
        vis[x][y][ban][k] = 1;
        // 判断是否到达终点
        if (x == n && y == m)
        {
            ans = dir;
            break;
        }
        // 判断是否遇到障碍物
        if (a[x][y] == 'X')
            k = 0;
        // 遍历四个方向
        for (int i = 0; i < 4; i++)
        {
            // 判断是否遇到禁止方向
            if (i == ban)
                continue;
            // 将新的节点加入队列
            q.push({x + dx[i], y + dy[i], dir + 1, ban, k});
        }
    }
    // 输出结果
    cout << ans;
}
int main()
{
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}