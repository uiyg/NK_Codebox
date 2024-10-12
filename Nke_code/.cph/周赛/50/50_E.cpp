#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int N = 1e6 + 5;
/*
С����һ��n ������������ڵ�Ϊ1����һ������ڸ��ڵ��ϣ�ÿ������ȸ�������ƶ�����ǰ�ڵ������һ���ӽڵ㣬����ȸ���������͵�һ��ͬ��Ƚڵ㣬����ʱ��λ��Ҷ�ӽڵ㣬��ֹͣ�ƶ���
�����ƶ����ӽڵ�Ĵ���������ֵ���𰸶�998244353 ȡģ��
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