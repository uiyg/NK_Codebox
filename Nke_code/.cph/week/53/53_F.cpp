#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1010;
char a[N][N];

// ����һ���ṹ�壬���ڴ洢��ǰ�ڵ����Ϣ
typedef array<int, 5> node;
queue<node> q;
// ����һ����ά���飬���ڼ�¼ÿ���ڵ��Ƿ񱻷��ʹ�
int vis[N][N][5][2];
// �����ĸ����򣬷ֱ�����������
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

// ����һ�����������ڽ���Թ�����
void solve()
{
    int n, m, ans = -1;
    cin >> n >> m;
    // ��ȡ�Թ���Ϣ
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    // �����������
    q.push({1, 1, 0, 0, 1});
    q.push({1, 1, 0, 1, 1});
    q.push({1, 1, 0, 2, 1});
    q.push({1, 1, 0, 3, 1});
    q.push({1, 1, 0, 4, 0});
    while (q.size())
    {
        // ȡ�������еĵ�һ���ڵ�
        auto [x, y, dir, ban, k] = q.front();
        q.pop();
        // �ж��Ƿ�Խ��
        if (x <= 0 || y <= 0 || x > n || y > m)
            continue;
        // �ж��Ƿ��Ѿ����ʹ�
        if (vis[x][y][ban][k])
            continue;
        // �ж��Ƿ������ϰ���
        if (a[x][y] == 'X' && !k)
            continue;
        // ���Ϊ�ѷ���
        vis[x][y][ban][k] = 1;
        // �ж��Ƿ񵽴��յ�
        if (x == n && y == m)
        {
            ans = dir;
            break;
        }
        // �ж��Ƿ������ϰ���
        if (a[x][y] == 'X')
            k = 0;
        // �����ĸ�����
        for (int i = 0; i < 4; i++)
        {
            // �ж��Ƿ�������ֹ����
            if (i == ban)
                continue;
            // ���µĽڵ�������
            q.push({x + dx[i], y + dy[i], dir + 1, ban, k});
        }
    }
    // ������
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