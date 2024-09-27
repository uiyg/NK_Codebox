#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, m;
    cin >> n >> m;
    if (n == 1)
    {
        cout << 2 << endl;
        return;
    }
    if (m == 1)
    {
        cout << n + 1 << endl;
    }
    else if (m == 2)
    {
        cout << n << endl;
    }
    else if (m == 3)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}