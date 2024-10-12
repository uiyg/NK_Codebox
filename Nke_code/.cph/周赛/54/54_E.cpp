#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;
// using pii = pair<int, int>;
int a[N], db[N];

void solve()
{
    // ��ȡ����
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // ��ʼ��dp����
    memset(db, 0x3f, sizeof(db));
    db[0] = 0;

    // ��̬�滮����
    for (int i = 1; i <= n; i++)
    {
        int st = max(0, i - a[i]);
        for (int j = st; j <= i - 1; j++)//�����ķ�Χ����i�������һ������iλ��
        {
            // ���µ���λ��j+a[i]����С��������
            db[j + a[i]] = min(db[j + a[i]], db[j] + 1);
        }
    }

    // ������
    if (db[n] == 0x3f3f3f3f)
        cout << -1 << endl;  // �޷������n��λ��
    else
        cout << db[n] << endl;  // �����С��������
}

int main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}