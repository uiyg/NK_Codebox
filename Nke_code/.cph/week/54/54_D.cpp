#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10;
// using pii = pair<int, int>;
ll a[N], b[N];

void solve()
{
    int n;
    queue<pair<int, int>> q; // ����һ��pair���͵Ķ���
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];            // ��������a��ֵ
    memset(b, 0x3f, sizeof(b)); // ������b��ʼ��Ϊһ���ܴ��ֵ
    b[1] = 0;                   // �������ľ���Ϊ0
    q.emplace(0, 1);            // �����������
    while (!q.empty())
    {
        int x = q.front().first;  // ��ǰ�ľ���
        int y = q.front().second; // ��ǰ��λ��
        q.pop();
        if (b[y] < x) // ����Ѿ��и��̵�·������y��������
            continue;
        for (int i = 1; i <= n; i++)
        {
            if (i == y) // ��������
                continue;
            if (a[y] % abs(y - i) == 0 && x + 1 < b[i]) // ������Ե���i��·������
            {
                b[i] = x + 1;        // ���µ���i����̾���
                q.emplace(x + 1, i); // ���µ�״̬�������
            }
        }
    }
    cout << b[n]; // ��������յ����̾���
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