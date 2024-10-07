#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
const int mod = 1e9 + 7;

vector<int> a[N]; // 图的邻接表
int son[N];       // 每个节点的儿子数

// 模幂运算函数
int skm(ll a, ll b)
{
    int t = 1;
    while (b)
    {
        if (b & 1)
        {
            t = t * a % mod;
        }
        a = a * a % mod;
        b >>= 1; // 开始少写了一个=,导致死循环
    }
    return t;
}

int ret; // 存储结果的全局变量
// 深度优先搜索函数，用于计算结果
void dfs(int x, int fa, ll p)
{
    ret = (ret + p) % mod;
    for (auto s : a[x])
    {
        if (s != fa)  // 如果s不是x的父亲
            son[x]++; // 增加x的儿子数
    }
    int t = skm(son[x], mod - 2); // 计算son[x]的模逆
    for (auto s : a[x])           // 再次遍历x的所有儿子
    {
        if (s != fa) // 如果s不是x的父亲
        {
            dfs(s, x, p * t % mod); // 递归调用dfs函数
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int v, u;
        cin >> v >> u;
        a[v].push_back(u);
        a[u].push_back(v);
    }
    dfs(1, 0, 1);        // 从节点1开始深度优先搜索
    cout << ret << endl; // 输出结果
}

int main()
{
    int T = 1;
    //    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}