#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
const int mod = 1e9 + 7;

vector<int> a[N]; // ͼ���ڽӱ�
int son[N];       // ÿ���ڵ�Ķ�����

// ģ�����㺯��
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
        b >>= 1; // ��ʼ��д��һ��=,������ѭ��
    }
    return t;
}

int ret; // �洢�����ȫ�ֱ���
// ��������������������ڼ�����
void dfs(int x, int fa, ll p)
{
    ret = (ret + p) % mod;
    for (auto s : a[x])
    {
        if (s != fa)  // ���s����x�ĸ���
            son[x]++; // ����x�Ķ�����
    }
    int t = skm(son[x], mod - 2); // ����son[x]��ģ��
    for (auto s : a[x])           // �ٴα���x�����ж���
    {
        if (s != fa) // ���s����x�ĸ���
        {
            dfs(s, x, p * t % mod); // �ݹ����dfs����
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
    dfs(1, 0, 1);        // �ӽڵ�1��ʼ�����������
    cout << ret << endl; // ������
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