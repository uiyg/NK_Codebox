#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 1000;
int a[N], id = 1,root[N];

// 定义一个结构体node，包含三个成员变量l、r、val
struct node
{
    int l, r, val;

} seg[N];

// 构建线段树
void build(int l, int r, int t)
{
    // 如果l等于r，说明已经到达叶子节点，直接返回
    if (l == r)
    {
        seg[t].val = 0;
        return;
    }

    // 计算中间位置
    int mid = (l + r) >> 1;
    // 递归构建左子树
    build(l, mid, seg[t].l);
    // 递归构建右子树
    build(mid + 1, r, seg[t].r);

    // 更新当前节点的值
    seg[t].val = seg[seg[t].l].val + seg[seg[t].r].val;
}

// 更新线段树
void update(int l, int r, int old, int now, int pos, int val)
{
    // 如果l等于r，说明已经到达叶子节点，直接返回
    if (l == r)
    {
        seg[now].val = seg[old].val + val;
        return;
    }
    // 计算中间位置
    int mid = (l + r) >> 1;
    // 复制old节点的左右子节点
    seg[now].l = seg[old].l;
    seg[now].r = seg[old].r;
    // 如果pos小于等于mid，说明更新左子树
    if (pos <= mid)
    {
        seg[now].l = ++id;
        update(l, mid, seg[old].l, seg[now].l, pos, val);
    }
    // 否则更新右子树
    else
    {
        seg[now].r = ++id;
        update(mid + 1, r, seg[old].r, seg[now].r, pos, val);
    }
    // 更新当前节点的值
    seg[now].val =seg[seg[now].l].val + seg[seg[now].r].val;
}
// 查询线段树
int query (int l, int r, int old, int now, int k){
    // 如果l等于r，说明已经到达叶子节点，直接返回
    if(l==r){
        return l;
    }
    // 计算中间位置
    int mid = (l+r)>>1;
    // 计算左子树的差值
    int d = seg[seg[now].l].val - seg[seg[old].l].val;

    // 如果差值小于等于k，说明答案在右子树
    if(d<=k){
        return query(mid+1, r, seg[old].r, seg[now].r, k-d);
    }
    // 否则答案在左子树
    else{
        return query(l, mid, seg[old].l, seg[now].l, k);
    }
}
// 解决问题
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1), b;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        b.emplace_back(v[i]);
    }

    // 对b进行排序并去重，标记叶子的数量
    std::sort(b.begin(), b.end());
    b.erase(std::unique(b.begin(), b.end()), b.end());

    // 定义一个函数get，用于获取v[i]在b中的位置
    auto get = [&](int x)
    {
        return lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
    };

    int len = b.size();
    // 构建线段树
    build(1, len, 1);

    // 初始化root数组
    for (int i = 1; i <= n;i++){
        int p=get(v[i]);
        root[i]=++id;
        // 更新线段树
        update(1, len, root[i-1], root[i], p, 1);
    }

    // 处理每个查询
    while (q--){
        int l, r;
        cin >> l >> r;
        int k=(r-l+1)/2;
        // 查询线段树
        int ans = query(1, len, root[l-1], root[r], k)-1;
        cout << b[ans] << "\n";
    }
}
int main()
{
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}