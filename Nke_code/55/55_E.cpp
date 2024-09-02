#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
int a[N], db[N][12];
// ���� (a^x) % mod �Ŀ����ݺ���
ll getmi(ll a, ll x)
{
    ll rt = 1;
    while (x)
    {
        if (x & 1)
            rt = rt * a % mod;
        a = a * a % mod, x >>= 1;
    }
    return rt;
}

// ��Ҫ���⺯��
void solve()
{
    int n;
    cin >> n;

    // ��ȡ���벢ֻ������λ��
    for (int i = 1; i <= n; i++)
    {
        int tamp;
        cin >> tamp;
        a[i] = tamp % 10;
    }

    // �����������������
    sort(a, a + n);

    // ��ʼ����̬�滮����
    db[0][1] = 1;

    // ��̬�滮����
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            // ���³˻��ĸ�λ��
            db[i][j * a[i] % 10] += db[i - 1][j];
            db[i][j * a[i] % 10] %= mod;
            // ���²��˵����
            db[i][j] += db[i - 1][j];
            db[i][j] %= mod;
        }
    }

    // �������մ�
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // �ۼ�ÿ��λ�õĹ��׵��ܴ���
        // (db[i][6] - db[i - 1][6] + mod) % mod: ������6��β����������������
        //   db[i][6]: ����Ϊi����������6��β������
        //   db[i-1][6]: ����Ϊi-1����������6��β������
        //   +mod �� %mod: ȷ�����Ϊ�Ǹ�������ģ����Χ��
        // getmi(2, n - i): ����2^(n-i)����ʾ��ʣ���n-i��λ����ѡ���ѡ������п�����
        // ������ %mod: ȷ�����ս����ģ����Χ��
        ans = (ans + (db[i][6] - db[i - 1][6] + mod) % mod * getmi(2, n - i) % mod) % mod;
    }

    // ������
    cout << ans << endl;
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