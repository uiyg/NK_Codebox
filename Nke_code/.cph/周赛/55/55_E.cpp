#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
int a[N], db[N][12];
// 计算 (a^x) % mod 的快速幂函数
ll getmi(ll a, ll x)
{
    ll rt = 1;
    while (x)
    {
        if (x & 1)
            rt = rt * a % mod;
        a = a * a % mod, x >>= 1;
    }
    return rt;
}

// 主要解题函数
void solve()
{
    int n;
    cin >> n;

    // 读取输入并只保留个位数
    for (int i = 1; i <= n; i++)
    {
        int tamp;
        cin >> tamp;
        a[i] = tamp % 10;
    }

    // 对输入数组进行排序
    sort(a, a + n);

    // 初始化动态规划数组
    db[0][1] = 1;

    // 动态规划过程
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            // 更新乘积的个位数
            db[i][j * a[i] % 10] += db[i - 1][j];
            db[i][j * a[i] % 10] %= mod;
            // 更新不乘的情况
            db[i][j] += db[i - 1][j];
            db[i][j] %= mod;
        }
    }

    // 计算最终答案
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // 累加每个位置的贡献到总答案中
        // (db[i][6] - db[i - 1][6] + mod) % mod: 计算以6结尾的序列数量的增量
        //   db[i][6]: 长度为i的序列中以6结尾的数量
        //   db[i-1][6]: 长度为i-1的序列中以6结尾的数量
        //   +mod 和 %mod: 确保结果为非负数并在模数范围内
        // getmi(2, n - i): 计算2^(n-i)，表示在剩余的n-i个位置中选择或不选择的所有可能性
        // 最外层的 %mod: 确保最终结果在模数范围内
        ans = (ans + (db[i][6] - db[i - 1][6] + mod) % mod * getmi(2, n - i) % mod) % mod;
    }

    // 输出结果
    cout << ans << endl;
}

int main()
{
    int T = 1;
    // cin >> T; // 如果有多组测试数据，取消此行注释
    while (T--)
    {
        solve();
    }
    return 0;
}