#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;
// using pii = pair<int, int>;
int a[N], db[N];

void solve()
{
    // 读取输入
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // 初始化dp数组
    memset(db, 0x3f, sizeof(db));
    db[0] = 0;

    // 动态规划过程
    for (int i = 1; i <= n; i++)
    {
        int st = max(0, i - a[i]);
        for (int j = st; j <= i - 1; j++)//布告板的范围，第i个布告板一定覆盖i位置
        {
            // 更新到达位置j+a[i]的最小操作次数
            db[j + a[i]] = min(db[j + a[i]], db[j] + 1);
        }
    }

    // 输出结果
    if (db[n] == 0x3f3f3f3f)
        cout << -1 << endl;  // 无法到达第n个位置
    else
        cout << db[n] << endl;  // 输出最小操作次数
}

int main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}