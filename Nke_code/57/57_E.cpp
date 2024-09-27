#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

// ���������������ĺ궨��
#define lson (rt << 1)
#define rson (rt << 1 | 1)

int a[100005];

// �����ڵ�ṹ��
struct node
{
    i64 sum, lz; // sum������ֵ
} tr[100005 << 2]; // ��������

// ������������
void build(int rt, int l, int r)
{
    if (l == r) // ���������Ҷ�ӽڵ�
    {
        tr[rt].sum = a[l]; // �洢ֵ��Ҷ�ӽڵ���
        return;
    }
    int mid = (l + r) >> 1; // �����м�����
    build(lson, l, mid); // �ݹ鹹��������
    build(rson, mid + 1, r); // �ݹ鹹��������
    tr[rt].sum = std::min(tr[lson].sum, tr[rson].sum); // ���µ�ǰ�ڵ�ĺ�
}

// ���¶�������
void update(int rt, int l, int r, int L, int R, int x)
{
    if (l >= L && r <= R) // �����ǰ���ڸ��·�Χ��
    {
        tr[rt].sum = x; // ���µ�ǰ�ڵ�ĺ�
        return;
    }
    int mid = l + r >> 1; // �����м�����
    if (mid >= L) // ����������ڸ��·�Χ��
        update(lson, l, mid, L, R, x); // �ݹ����������
    if (mid < R) // ����������ڸ��·�Χ��
    {
        update(rson, mid + 1, r, L, R, x); // �ݹ����������
    }
    tr[rt].sum = std::min(tr[lson].sum, tr[rson].sum); // ���µ�ǰ�ڵ�ĺ�
}

// ��ѯ��������
i64 query(int rt, int l, int r, int L, int R)
{
    if (l >= L && r <= R) // �����ǰ���ڲ�ѯ��Χ��
    {
        return tr[rt].sum; // ���ص�ǰ�ڵ�ĺ�
    }
    i64 ans = 1e9 + 1; // ��ʼ����Ϊ�����
    int mid = l + r >> 1; // �����м�����
    if (mid >= L) // ����������ڲ�ѯ��Χ��
        ans = std::min(ans, query(lson, l, mid, L, R)); // �ݹ��ѯ������
    if (mid < R) // ����������ڲ�ѯ��Χ��
        ans = std::min(ans, query(rson, mid + 1, r, L, R)); // �ݹ��ѯ������
    return ans; // ������С��
}

// �������ĺ���
void solve()
{
    int t;
    std::cin >> t; // ��ȡ������������
    int n = 0; // ��ʼ��Ԫ������
    std::vector<int> pre(t + 1); // ǰ׺�����飬�洢�ۻ���
    for (int i = 1; i <= t; i++)
    {
        int x;
        std::cin >> x; // ��ȡ��ǰ����������Ԫ������
        n += x; // ����Ԫ������
        pre[i] = pre[i - 1] + x; // ����ǰ׺������
        for (int j = pre[i - 1] + 1; j <= pre[i]; j++)
        {
            std::cin >> a[j]; // ��ȡԪ��
        }
    }
    // std::cout << n << '\n'; // ���ԣ���ӡԪ������
    build(1, 1, n); // ��������

    int m;
    std::cin >> m; // ��ȡ��������
    while (m--) // ִ��ÿ������
    {
        int op;
        std::cin >> op; // ��ȡ��������
        if (op == 1) // ���²���
        {
            int i, j, x;
            std::cin >> i >> j >> x; // ��ȡ���²���
            int pos = pre[i - 1] + j; // �������λ��
            update(1, 1, n, pos, pos, x); // ���¶���
        }
        else // ��ѯ����
        {
            int x;
            std::cin >> x; // ��ȡ��ѯ����
            std::cout << query(1, 1, n, 1, pre[x]) << '\n'; // ��ѯ��������ӡ���
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
