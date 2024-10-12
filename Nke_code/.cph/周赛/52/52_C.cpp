#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int N = 1e5 + 5;

int main()
{ // 相同数抵消，正负数抵消，所以先看整数抵消后的个数，再看差值
    int n, a[N] = {0}, ans = 0, cnt1 = 0, cnt2 = 0;
    map<int, int> mp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < 0)
            cnt1++;
        else
            mp[a[i]]++;
    }
    for (auto u : mp)
    {
        cnt2 += u.second % 2;
    }
    if (cnt1 > cnt2)
        ans = (cnt1 - cnt2) % 2;
    else
        ans = cnt2 - cnt1;
    cout << ans;

    return 0;
}