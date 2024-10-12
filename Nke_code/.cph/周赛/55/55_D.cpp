#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10;
int a[N][N], dp[N][N], vis[N][N];
// 定义四个方向：右、下、左、上
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void solve()
{
    int n;
    cin >> n;
    // 读入迷宫数据
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    // 设置迷宫边界
    for (int i = 0; i <= n; i++)
    {
        a[i][0] = 1;
        a[0][i] = 1;
        a[i][n + 1] = 1;
        a[n + 1][i] = 1;
    }
    queue<pair<int, int>> q;
    q.push({1, 1}); // 起点为(1,1)
    vis[1][1] = 1;  // 标记起点已访问
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // 遍历四个方向
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (vis[nx][ny])
                continue; // 如果已访问，跳过
            if (a[nx][ny] == 1)
            {
                // 如果遇到障碍物，沿着当前方向滑动
                while (a[nx - dx[i]][ny - dy[i]] == 0)
                {
                    nx -= dx[i];
                    ny -= dy[i];
                }
            }
            if (vis[nx][ny])
                continue; // 滑动后再次检查是否已访问
            vis[nx][ny] = 1; // 标记为已访问
            dp[nx][ny] = dp[x][y] + 1; // 更新到达该点的步数
            q.push({nx, ny}); // 将新位置加入队列
        }
    }
    // 输出结果
    if (dp[n][n] == 0)
        cout << -1 << endl; // 无法到达终点
    else
        cout << dp[n][n] << endl; // 输出最少步数
}

int main()
{
    int T = 1;
    // cin >> T; // 如果有多组测试数据，取消此行注释
    while (T--)
    {
        solve();
    }
    return 0;
}