#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; ++i)
using namespace std;
using ll = long long;
const int N = 1e6 + 50;
const int mod = 998244353;
#define int long long
ll fa[N], vis[N];
ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// �����ĸ�������ƶ�
ll getfa(ll x)
{
    // ��ȡx�ĸ��ڵ�
    return fa[x] == x ? x : fa[x] = getfa(fa[x]);
}
// ���Ҳ��鼯�ĸ��ڵ�
void merge(ll x, ll y)
{
    // �ϲ���������
    x = getfa(x), y = getfa(y);
    if (x == y)
        return;
    fa[y] = x;
}
// �ϲ���������
vector<ll> g[N];
struct node
{
    ll i, j, w;
} a[N];

void solve()
{
    // �������ĺ���
    ll n, ans = 0;
    cin >> n;
    rep(i, 1, n) rep(j, 1, n)
    {
        ll w;
        cin >> w;
        a[(i - 1) * n + j].i = i, a[(i - 1) * n + j].j = j, a[(i - 1) * n + j].w = w;
        // ����ת��һ������
    }
    // ��ȡ��������
    sort(a + 2, a + n * n, [&](node x, node y)
         { return x.w < y.w; });
    // �����ݽ�������
    rep(i, 1, n * n) vis[i] = 0, fa[i] = i;
    // ��ʼ�����鼯�ͷ�������
    vis[1] = vis[n * n] = 1;
    ans = max(a[1].w, a[n * n].w);
    // ��ʼ����
    rep(k, 2, n * n - 1)
    {
        ans = max(ans, a[k].w);
        int i = (a[k].i - 1) * n + a[k].j;
        vis[i] = 1;
        rep(j, 0, 3)
        {
            ll x = dx[j] + a[k].i, y = dy[j] + a[k].j;
            if (1 <= x && x <= n && 1 <= y && y <= n && vis[(x - 1) * n + y])
            {
                merge(i, (x - 1) * n + y);
            }
        }
        if (getfa(1) == getfa(n * n))
            return cout << ans << "\n", void();
    }
}
// �������ĺ���
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}
// ������
