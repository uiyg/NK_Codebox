#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int N = 1e6 + 5;
/*
小红有一棵n 个点的树，根节点为1，有一个物块在根节点上，每次它会等概率随机移动到当前节点的其中一个子节点，而后等概率随机传送到一个同深度节点，若此时它位于叶子节点，则停止移动。
求其移动到子节点的次数的期望值，答案对998244353 取模。
*/
int main()
{
    // int T = 1;
    // // cin >> T;
    // while (T--)
    // {
    //     solve();
    // }
    int n;
    cin >> n;
    vector<vector<int>> G(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> dep(n + 1);
    vector<int> cnt(n + 1), cntleaf(n + 1);
    dep[0] = 0;
    auto dfs = [&](auto self, int u, int fa) -> void
    {
        dep[u] = dep[fa] + 1;
        cnt[dep[u]]++;
        cntleaf[dep[u]] += (u != 1 && G[u].size() == 1);
        for (auto &ne : G[u])
        {
            if (ne == fa)
            {
                continue;
            }
            self(self, ne, u);
        }
    };
    dfs(dfs, 1, 0);
    auto inv = [&](int a)
    {
        int b = mod - 2;
        ll ret = 1;
        while (b)
        {
            if (b & 1)
                ret = ret * a % mod;
            a = 1LL * a * a % mod;
            b >>= 1LL;
        }
        return ret;
    };
    vector<int> P(n + 1);
    P[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        P[i] = 1LL * P[i - 1] * (cnt[i] - cntleaf[i]) % mod * inv(cnt[i]) % mod;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = (ans + P[i]) % mod;
    }
    cout << ans;
    return 0;
}