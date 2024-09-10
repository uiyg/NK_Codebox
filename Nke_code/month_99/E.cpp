#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
ll a[N], h[N];

void solve()
{
    int n, m;
    cin >> n >> m; // ����Ԫ�ص����������������
    vector<int> h(n + 1), a(n + 1); // ��ʼ���߶Ⱥ���ʼ���������
    // �������ݡ�
    for (int i = 1; i <= n; i++)
        cin >> h[i]; // ����ÿ��Ԫ�صĸ߶ȡ�
    for (int i = 1; i <= n; i++)
        cin >> a[i]; // ����ÿ��Ԫ�ص���ʼ�㡣

    // �����ߡ�
    vector<pair<int, int>> edge;
    for (int i = 1; i <= n; i++)
    {
        edge.push_back({a[i], a[i] + h[i]});
    }
    // ����ߡ�
    sort(edge.begin(), edge.end()); // ���߰���������

    vector<int> groups;
    int st = -2e9, ed = -2e9, c = 0; // ��ʼ�������ʼ�㡢�յ��Ԫ��������
    for (auto [start, end] : edge)
    {
        if (ed >= start || st == -2e9)
        {
            ed = max(ed, end); // ��������յ㡣
            if (st == -2e9)
                st = start; // ���������ʼ�㡣
            c++; // ��������Ԫ�ص�������
        }
        else
        {
            groups.push_back(c); // ������Ԫ�ص�������ӵ��������С�
            c = 1; // ��������Ԫ�ص�������
            st = start, ed = end; // ���������ʼ����յ㡣
        }
    }
    if (st != -2e9)
    {
        groups.push_back(c);
    }

    sort(groups.rbegin(), groups.rend());
    int ans = 0;
    for (int i = 0; i < min(m, (int)groups.size()); i++)
    {
        ans += groups[i];
    }
    cout << ans << '\n';
}

int main()
{
    int T = 1;
    cin >> T; // ����ж���������ݣ�ȡ������ע��
    while (T--)
    {
        solve();
    }
    return 0;
}