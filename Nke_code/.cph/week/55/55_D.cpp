#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10;
int a[N][N], dp[N][N], vis[N][N];
// �����ĸ������ҡ��¡�����
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void solve()
{
    int n;
    cin >> n;
    // �����Թ�����
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    // �����Թ��߽�
    for (int i = 0; i <= n; i++)
    {
        a[i][0] = 1;
        a[0][i] = 1;
        a[i][n + 1] = 1;
        a[n + 1][i] = 1;
    }
    queue<pair<int, int>> q;
    q.push({1, 1}); // ���Ϊ(1,1)
    vis[1][1] = 1;  // �������ѷ���
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // �����ĸ�����
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (vis[nx][ny])
                continue; // ����ѷ��ʣ�����
            if (a[nx][ny] == 1)
            {
                // ��������ϰ�����ŵ�ǰ���򻬶�
                while (a[nx - dx[i]][ny - dy[i]] == 0)
                {
                    nx -= dx[i];
                    ny -= dy[i];
                }
            }
            if (vis[nx][ny])
                continue; // �������ٴμ���Ƿ��ѷ���
            vis[nx][ny] = 1; // ���Ϊ�ѷ���
            dp[nx][ny] = dp[x][y] + 1; // ���µ���õ�Ĳ���
            q.push({nx, ny}); // ����λ�ü������
        }
    }
    // ������
    if (dp[n][n] == 0)
        cout << -1 << endl; // �޷������յ�
    else
        cout << dp[n][n] << endl; // ������ٲ���
}

int main()
{
    int T = 1;
    // cin >> T; // ����ж���������ݣ�ȡ������ע��
    while (T--)
    {
        solve();
    }
    return 0;
}