#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
ll a[N], h[N];

void solve()
{
    int n, m;
    cin >> n >> m; // 输入元素的数量和最大组数。
    vector<int> h(n + 1), a(n + 1); // 初始化高度和起始点的向量。
    // 输入数据。
    for (int i = 1; i <= n; i++)
        cin >> h[i]; // 输入每个元素的高度。
    for (int i = 1; i <= n; i++)
        cin >> a[i]; // 输入每个元素的起始点。

    // 创建边。
    vector<pair<int, int>> edge;
    for (int i = 1; i <= n; i++)
    {
        edge.push_back({a[i], a[i] + h[i]});
    }
    // 排序边。
    sort(edge.begin(), edge.end()); // 将边按升序排序。

    vector<int> groups;
    int st = -2e9, ed = -2e9, c = 0; // 初始化组的起始点、终点和元素数量。
    for (auto [start, end] : edge)
    {
        if (ed >= start || st == -2e9)
        {
            ed = max(ed, end); // 更新组的终点。
            if (st == -2e9)
                st = start; // 更新组的起始点。
            c++; // 增加组内元素的数量。
        }
        else
        {
            groups.push_back(c); // 将组内元素的数量添加到组向量中。
            c = 1; // 重置组内元素的数量。
            st = start, ed = end; // 更新组的起始点和终点。
        }
    }
    if (st != -2e9)
    {
        groups.push_back(c);
    }

    sort(groups.rbegin(), groups.rend());
    int ans = 0;
    for (int i = 0; i < min(m, (int)groups.size()); i++)
    {
        ans += groups[i];
    }
    cout << ans << '\n';
}

int main()
{
    int T = 1;
    cin >> T; // 如果有多组测试数据，取消此行注释
    while (T--)
    {
        solve();
    }
    return 0;
}