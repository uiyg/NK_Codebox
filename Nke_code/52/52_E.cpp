#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int N = 1e5 + 5;

ll fa[N] = {0}, a[N] = {0};
ll minn=1e9;

ll find(int x)
{
    if (fa[x] == x)
        return x;
    else
        return fa[x] = find(fa[x]);
}
int main()
{
    int n, m;
    ll ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        x = find(x);
        y = find(y);
        if (x != y)
        {
            fa[y] = x;
            a[x]=max(a[x], a[y]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(fa[i]==i)
        {
            ans += a[i];
            minn = min(minn, a[i]);
        }
    }
    cout << ans - minn;
    return 0;
}