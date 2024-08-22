#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
int solve[110][5010], db[110][30];
int main()
{
    int n, m, target, flag;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int mi = INT16_MAX;
        for (int j = 1; j <= m; j++)
        {
            cin >> db[i][j];
            mi = min(mi, db[i][j]);
        }
        flag += mi;
    }
    cin >> target;

    for (int i = 1; i <= n; i++)
    {
        for (int k = 5000; k > 0; k--)
        {
            for (int j = 1; j <= m; j++)
            {
                if (k >= db[i][j])
                    solve[i][k] = max(solve[i][k], solve[i - 1][k - db[i][j]] + db[i][j]);
            }
        }
    }
    int ans = 5000;
    for (int i = flag; i <= 5000; i++)
    {
        ans = min(ans, abs(solve[n][i] - target));
    }
    cout << ans << endl;
    return 0;
}