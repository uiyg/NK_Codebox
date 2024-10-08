#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 1000;
int a[N], id = 1,root[N];

// ����һ���ṹ��node������������Ա����l��r��val
struct node
{
    int l, r, val;

} seg[N];

// �����߶���
void build(int l, int r, int t)
{
    // ���l����r��˵���Ѿ�����Ҷ�ӽڵ㣬ֱ�ӷ���
    if (l == r)
    {
        seg[t].val = 0;
        return;
    }

    // �����м�λ��
    int mid = (l + r) >> 1;
    // �ݹ鹹��������
    build(l, mid, seg[t].l);
    // �ݹ鹹��������
    build(mid + 1, r, seg[t].r);

    // ���µ�ǰ�ڵ��ֵ
    seg[t].val = seg[seg[t].l].val + seg[seg[t].r].val;
}

// �����߶���
void update(int l, int r, int old, int now, int pos, int val)
{
    // ���l����r��˵���Ѿ�����Ҷ�ӽڵ㣬ֱ�ӷ���
    if (l == r)
    {
        seg[now].val = seg[old].val + val;
        return;
    }
    // �����м�λ��
    int mid = (l + r) >> 1;
    // ����old�ڵ�������ӽڵ�
    seg[now].l = seg[old].l;
    seg[now].r = seg[old].r;
    // ���posС�ڵ���mid��˵������������
    if (pos <= mid)
    {
        seg[now].l = ++id;
        update(l, mid, seg[old].l, seg[now].l, pos, val);
    }
    // �������������
    else
    {
        seg[now].r = ++id;
        update(mid + 1, r, seg[old].r, seg[now].r, pos, val);
    }
    // ���µ�ǰ�ڵ��ֵ
    seg[now].val =seg[seg[now].l].val + seg[seg[now].r].val;
}
// ��ѯ�߶���
int query (int l, int r, int old, int now, int k){
    // ���l����r��˵���Ѿ�����Ҷ�ӽڵ㣬ֱ�ӷ���
    if(l==r){
        return l;
    }
    // �����м�λ��
    int mid = (l+r)>>1;
    // �����������Ĳ�ֵ
    int d = seg[seg[now].l].val - seg[seg[old].l].val;

    // �����ֵС�ڵ���k��˵������������
    if(d<=k){
        return query(mid+1, r, seg[old].r, seg[now].r, k-d);
    }
    // �������������
    else{
        return query(l, mid, seg[old].l, seg[now].l, k);
    }
}
// �������
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

    // ��b��������ȥ�أ����Ҷ�ӵ�����
    std::sort(b.begin(), b.end());
    b.erase(std::unique(b.begin(), b.end()), b.end());

    // ����һ������get�����ڻ�ȡv[i]��b�е�λ��
    auto get = [&](int x)
    {
        return lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
    };

    int len = b.size();
    // �����߶���
    build(1, len, 1);

    // ��ʼ��root����
    for (int i = 1; i <= n;i++){
        int p=get(v[i]);
        root[i]=++id;
        // �����߶���
        update(1, len, root[i-1], root[i], p, 1);
    }

    // ����ÿ����ѯ
    while (q--){
        int l, r;
        cin >> l >> r;
        int k=(r-l+1)/2;
        // ��ѯ�߶���
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