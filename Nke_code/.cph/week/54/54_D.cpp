#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 10;
// using pii = pair<int, int>;
ll a[N], b[N];

void solve()
{
    int n;
    queue<pair<int, int>> q; // 定义一个pair类型的队列
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];            // 输入数组a的值
    memset(b, 0x3f, sizeof(b)); // 将数组b初始化为一个很大的值
    b[1] = 0;                   // 设置起点的距离为0
    q.emplace(0, 1);            // 将起点加入队列
    while (!q.empty())
    {
        int x = q.front().first;  // 当前的距离
        int y = q.front().second; // 当前的位置
        q.pop();
        if (b[y] < x) // 如果已经有更短的路径到达y，则跳过
            continue;
        for (int i = 1; i <= n; i++)
        {
            if (i == y) // 跳过自身
                continue;
            if (a[y] % abs(y - i) == 0 && x + 1 < b[i]) // 如果可以到达i且路径更短
            {
                b[i] = x + 1;        // 更新到达i的最短距离
                q.emplace(x + 1, i); // 将新的状态加入队列
            }
        }
    }
    cout << b[n]; // 输出到达终点的最短距离
}

int main()
{
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}