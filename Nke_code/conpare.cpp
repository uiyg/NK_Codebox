#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int ret;
vector<int> e[N];
int son[N];

int ksm(ll a, ll b)
{
    int t = 1;

    while (b)
    {
        if (b & 1)
        {
            t = t * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return t;
}

void dfs(int x, int fa, ll p)
{
    // cout << "x = " << x << " fa = " << fa << " p = " << p << endl;
    ret = (ret + p) % MOD; // �����p��ʾ���Ǹ���
    for (auto i : e[x])
    {
        if (i != fa)
        {
            son[x]++;
        }
    }
    int t = ksm(son[x], MOD - 2); // ����
    for (auto i : e[x])
    {
        if (i != fa)
        {
            dfs(i, x, p * t % MOD);
        }
    }
}

signed main()
{
    int n;
    cin >> n;
    for (int i = 1, u, v; i <= n - 1; i++)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0, 1); // �����1�ĸ��ڵ�����Ϊ��0  ���0�ǲ����ڵ� ��������ѭ��
    cout << ret << endl;
    return 0;
}
