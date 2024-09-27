#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

// 左子树和右子树的宏定义
#define lson (rt << 1)
#define rson (rt << 1 | 1)

int a[100005];

// 段树节点结构体
struct node
{
    i64 sum, lz; // sum和懒惰值
} tr[100005 << 2]; // 段树数组

// 构建段树函数
void build(int rt, int l, int r)
{
    if (l == r) // 基本情况：叶子节点
    {
        tr[rt].sum = a[l]; // 存储值在叶子节点中
        return;
    }
    int mid = (l + r) >> 1; // 计算中间索引
    build(lson, l, mid); // 递归构建左子树
    build(rson, mid + 1, r); // 递归构建右子树
    tr[rt].sum = std::min(tr[lson].sum, tr[rson].sum); // 更新当前节点的和
}

// 更新段树函数
void update(int rt, int l, int r, int L, int R, int x)
{
    if (l >= L && r <= R) // 如果当前段在更新范围内
    {
        tr[rt].sum = x; // 更新当前节点的和
        return;
    }
    int mid = l + r >> 1; // 计算中间索引
    if (mid >= L) // 如果左子树在更新范围内
        update(lson, l, mid, L, R, x); // 递归更新左子树
    if (mid < R) // 如果右子树在更新范围内
    {
        update(rson, mid + 1, r, L, R, x); // 递归更新右子树
    }
    tr[rt].sum = std::min(tr[lson].sum, tr[rson].sum); // 更新当前节点的和
}

// 查询段树函数
i64 query(int rt, int l, int r, int L, int R)
{
    if (l >= L && r <= R) // 如果当前段在查询范围内
    {
        return tr[rt].sum; // 返回当前节点的和
    }
    i64 ans = 1e9 + 1; // 初始化答案为无穷大
    int mid = l + r >> 1; // 计算中间索引
    if (mid >= L) // 如果左子树在查询范围内
        ans = std::min(ans, query(lson, l, mid, L, R)); // 递归查询左子树
    if (mid < R) // 如果右子树在查询范围内
        ans = std::min(ans, query(rson, mid + 1, r, L, R)); // 递归查询右子树
    return ans; // 返回最小和
}

// 解决问题的函数
void solve()
{
    int t;
    std::cin >> t; // 读取测试用例数量
    int n = 0; // 初始化元素总数
    std::vector<int> pre(t + 1); // 前缀和数组，存储累积和
    for (int i = 1; i <= t; i++)
    {
        int x;
        std::cin >> x; // 读取当前测试用例的元素数量
        n += x; // 更新元素总数
        pre[i] = pre[i - 1] + x; // 更新前缀和数组
        for (int j = pre[i - 1] + 1; j <= pre[i]; j++)
        {
            std::cin >> a[j]; // 读取元素
        }
    }
    // std::cout << n << '\n'; // 调试：打印元素总数
    build(1, 1, n); // 构建段树

    int m;
    std::cin >> m; // 读取操作数量
    while (m--) // 执行每个操作
    {
        int op;
        std::cin >> op; // 读取操作类型
        if (op == 1) // 更新操作
        {
            int i, j, x;
            std::cin >> i >> j >> x; // 读取更新参数
            int pos = pre[i - 1] + j; // 计算更新位置
            update(1, 1, n, pos, pos, x); // 更新段树
        }
        else // 查询操作
        {
            int x;
            std::cin >> x; // 读取查询参数
            std::cout << query(1, 1, n, 1, pre[x]) << '\n'; // 查询段树并打印结果
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    // std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
