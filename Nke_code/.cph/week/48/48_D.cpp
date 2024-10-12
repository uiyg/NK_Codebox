
#include <iostream>
#include <cmath>
#define ll long long
using namespace std;
// 有难度不像D题
ll n, a[100010];
ll gt(int pos, ll val)
{
    ll r = 0;
    if (pos != 1)
    {
        r += abs(val - a[pos - 1]);
    }
    if (pos != n)
    {
        r += abs(val - a[pos + 1]);
    }
    return r;
}
ll nul[100010], pre[100010], suf[100010];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0, cg = 1e15;
    for (int i = 2; i <= n; i++)
    {
        ans += abs(a[i] - a[i - 1]);
    }
    pre[0] = suf[n + 1] = 1e15;
    for (int i = 1; i <= n; i++)
    {
        nul[i] = gt(i, a[i] * 2ll) - gt(i, a[i]);
        pre[i] = min(nul[i], pre[i - 1]);
    }
    for (int i = n; i >= 1; i--)
    {
        suf[i] = min(suf[i + 1], nul[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        ll tmp = gt(i, a[i] / 2ll) - gt(i, a[i]);
        ll mnmul = 1e15;
        if (i - 2 >= 1)
        {
            mnmul = min(mnmul, pre[i - 2]);
        }
        if (i + 2 <= n)
        {
            mnmul = min(mnmul, suf[i + 2]);
        }
        cg = min(cg, tmp + mnmul);
    }
    for (int i = 1; i <= n; i++)
    {
        cg = min(cg, gt(i, a[i] / 2ll * 2ll) - gt(i, a[i]));
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j : {i - 1, i + 1})
        {
            if (j >= 1 && j <= n)
            {
                ll svi = a[i], svj = a[j];
                ll r1 = gt(i, a[i]) + gt(j, a[j]) - abs(a[i] - a[j]);
                a[i] /= 2ll;
                a[j] *= 2ll;
                ll r2 = gt(i, a[i]) + gt(j, a[j]) - abs(a[i] - a[j]);
                cg = min(cg, r2 - r1);
                a[i] = svi;
                a[j] = svj;
            }
        }
    }
    cout << ans + cg << endl;
    return 0;
}
