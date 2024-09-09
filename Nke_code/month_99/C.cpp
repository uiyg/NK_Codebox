#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e3 + 7;
const int N = 1e3 + 10;
char ma[N][N];
int vis[N][N], tx[N], ty[N];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;
int n, m, startx, starty, endx, endy;

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> ma[i][j];
            if (ma[i][j] == 'S')
            {
                startx = i;
                starty = j;
            }
            if (ma[i][j] == 'E')
            {
                endx = i;
                endy = j;
            }
        }
    }
    // cout << endx<<endy;
    q.emplace(endx, endy);
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        // cout << x << ' ' << y;
        q.pop();
        if (x < 1 || x > n || y < 1 || y > m || vis[x][y])
            continue;
        vis[x][y] = 2;
        tx[x] = tx[x - 1] = tx[x + 1] = 1;
        ty[y] = ty[y - 1] = ty[y + 1] = 1;

        for (int i = 0; i < 4; i++)
        {
            int nx, ny;
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m)
                continue;
            if (ma[nx][ny] == '.' && !vis[nx][ny])
                q.emplace(nx, ny);
        }
    }
    bool ok = (vis[startx][starty] == 2);

    q.emplace(startx, starty);

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        if (vis[x][y] == 2)
        {
            ok = true;
            break;
        }
        if (vis[x][y])
            continue;
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m)
                continue;
            if (vis[nx][ny] == 2)
                ok = true;
            if (i < 2 && ty[y])
                ok = true;
            if (i > 1 && tx[x])
                ok = true;
            if (ma[nx][ny] == '.' && !vis[nx][ny])
                q.emplace(nx, ny);
        }
    }
    if (ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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