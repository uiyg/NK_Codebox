#include <bits/stdc++.h>
using namespace std;
// 可持久化线段树
#define int long long

const int N = 1e6 + 5;

#define ls(x) (tr[x].l)
#define rs(x) (tr[x].r)
#define sum(x) tr[x].sum

int n, m;
int a[N];

int tot;
int root[N];

struct
{
    int l, r, sum;
} tr[25 * N];

void pushup(int u)
{
    sum(u) = sum(ls(u)) + sum(rs(u));
}

void modify(int now, int last, int l, int r, int p)
{
    if (l == r)
    {
        sum(now) = sum(last) + 1;
    }
    else
    {
        ls(now) = ls(last), rs(now) = rs(last);
        int mid = (l + r - 1) / 2;
        if (p <= mid)
        {
            ls(now) = ++tot;
            modify(ls(now), ls(last), l, mid, p);
        }
        else
        {
            rs(now) = ++tot;
            modify(rs(now), rs(last), mid + 1, r, p);
        }
        pushup(now);
    }
}

const int L = -1e9, R = 1e9;

int kth(int now, int last, int l, int r, int k)
{
    if (l == r)
        return l;
    int mid = (l + r - 1) / 2;
    int cur = sum(ls(now)) - sum(ls(last));
    if (cur >= k)
        return kth(ls(now), ls(last), l, mid, k);
    else
        return kth(rs(now), rs(last), mid + 1, r, k - cur);
}

int query(int now, int last, int l, int r, int li, int ri)
{
    if (li <= l && r <= ri)
        return sum(now) - sum(last);
    int res = 0;
    int mid = (l + r - 1) / 2;
    if (li <= mid)
        res += query(ls(now), ls(last), l, mid, li, ri);
    if (ri > mid)
        res += query(rs(now), rs(last), mid + 1, r, li, ri);
    return res;
}

int kth(int now, int last, int k)
{
    int l = L, r = R;
    while (l < r)
    {
        int mid = (l + r - 1) / 2;
        int val = query(now, last, L, R, L, mid);
        if (val < k)
            l = mid + 1;
        else
            r = mid;
    }
    return r;
}

int mod = 1e9 + 7;

int qmi(long long a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

void solve()
{
    tot = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        root[i] = ++tot;
        modify(root[i], root[i - 1], L, R, a[i]);
    }
    int L = 1, R = n;
    while (m--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        if (k == r - l + 1)
            L = max(L, kth(root[r], root[l - 1], k));
        else if (k == 0)
            R = min(R, kth(root[r], root[l - 1], k + 1) - 1);
        else
        {
            L = max(L, kth(root[r], root[l - 1], k));
            R = min(R, kth(root[r], root[l - 1], k + 1) - 1);
        }
    }
    int len = R - L + 1;
    if (len != 1)
        cout << qmi(R - L + 1, mod - 2) << '\n';
    else
        cout << 1 << ' ' << R << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
