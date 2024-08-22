#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
ll quickpow(ll a)//求逆元（费马小定理、快速冥，条件：a不是mod的的倍数）
{
    ll ans = 1;
    ll b = mod - 2;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}
ll C(ll n, ll m)
{
    ll a = 1, b = 1;
    for (int i = m; i > n; i--)
    {
        a = a * i % mod;
        b = b * (i - n) % mod;
    }
    return (a *quickpow(b)) % mod;
}
int main()
{
    int n, ans = 0, cnt = 0;
    cin >> n;
    string s;
    cin >> s;
    // cout << s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            ans++;
        else if (s[i] == ')')
            ans--;
        else
            cnt++;
    }
    ll t = (cnt - abs(ans)) % mod;
    if (t % 2 == 0)
        cout << C(t / 2, cnt);
    else
        cout << 0;
    return 0;
}