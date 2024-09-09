#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 5;
const int N = 2e7 + 10;
int cnt = 0;
bool st[N];
ll prime[N];
// ʹ�ð�����˹����ɸ����������
void get_prime()
{
    for (int i = 2; i < N; i++)
    {
        if (!st[i])
            prime[cnt++] = i;  // ���i��������������ӵ�����������
        for (int j = 0; prime[j] < N / i; j++)
        {
            st[prime[j] * i] = true;  // ���prime[j]�ı���Ϊ������
            if (i % prime[j] == 0)
                break;  // �Ż�����i�ܱ�prime[j]����ʱ����ѭ��
        }
    }
}

// �������ĺ���
void solve()
{   
    map<int, int> a;  // ���ڴ洢�������ֵ�ӳ��
    int n;
    cin >> n;  // ��ȡԪ������
    for (int i = 1; i <= n; i++)
    {
        int tamp;
        cin >> tamp;
        a[tamp] = 1;  // ��ӳ���б�����������Ϊ����
    }
    for (int i = 0; i < cnt; i++)
    {
        if (a[prime[i]] == 0)
        {
            cout << prime[i] << endl;  // �����һ�����������е�����
            break;
        }
    }
    // cout << a[2] ;  // ע�͵��ĵ������
}

int main()
{
    int T = 1;
    cin >> T; // ����ж���������ݣ�ȡ������ע��
    get_prime();
    while (T--)
    {
        solve();
    }
    return 0;
}