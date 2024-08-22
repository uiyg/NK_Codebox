#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
int a[N], n;

// ����Ƿ���Խ������е�ÿ��Ԫ�ض�����x��ֱ�������ٳ�Ϊֹ�����õ��ļ��ϴ�С�Ƿ�Ϊx
int chek(int x)
{
    set<int> q;
    for (int i = 1; i <= n; i++)
    {
        int m = a[i];
        // ��m����x��ֱ�������ٳ�Ϊֹ
        while (m >= x && m)
            m /= 2;
        // ����������Ѿ�����m����m��������2��ֱ�����ٴ���
        while (q.count(m) && m)
            m /= 2;
        q.insert(m);
    }
    // ���ؼ��ϵĴ�С�Ƿ�Ϊx
    return q.size() == x;
}
void solve()
{
    // �������鳤��
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        // ��������Ԫ��
        cin >> a[i];
    }
    // ���ֲ���
    int l = 1, r = n, ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l)/ 2;
        // ������Գ���mid������´𰸣����������Ҹ����mid
        if (chek(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        // ���򣬼������Ҹ�С��mid
        else
            r = mid - 1;
    }
    // �����
    cout << ans << endl;
}
int main()
{
    int T;
    // ���������������
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}