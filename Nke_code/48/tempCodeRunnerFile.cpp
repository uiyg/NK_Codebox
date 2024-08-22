#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans = 0, sum[26][200010] = {0}, num[26][200010] = {0};
int main()
{

    string s;
    cin >> s;
    s = ' ' + s;
    cout << s;
    int n = s.size();
    for (int i = 1; i <= n; i++)
    {

        for (int j = 0; j < 25; j++)
        {
            if ('a' + j == s[i])
            {
                sum[j][i] = sum[j][i - 1];
                num[j][i] = num[j][i - 1];
            }
            else
            {
                sum[j][i] = sum[j][i - 1] + 1;
                num[j][i] = num[j][i - 1] + n - i + 1;
            }
        }
    }
    ll c1, c2;
    for (int i = 1; i <= n; i++)
    {
        int j = n - i + 1, c = s[i] - 'a';
        j = max(j, i);
        c1 = (sum[c][j] - sum[c][i]) * i;
        c2 = num[c][j] - num[c][i];
        ans += c1 + c2;
    }
    cout << ans;
    return 0;
}