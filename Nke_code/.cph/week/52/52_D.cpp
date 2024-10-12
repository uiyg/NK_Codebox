#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int N = 1e5 + 5;

int main()
{
    // �������n���ַ���s���ַ���ans�����ȶ���q
    int n;
    string s, ans;
    // ����һ�����ȶ���q������pair�ĵ�һ��Ԫ��Ϊ�ַ����ڶ���Ԫ��Ϊ�ַ���
    priority_queue<pair<char, string>> q;
    // ����n
    cin >> n;
    // ѭ��n�Σ������ַ���s������s�ĵ�һ���ַ���s��Ϊpair�������ȶ���q��
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        q.push({s[0], s});
    }
    // �����ȶ���q��Ϊ��ʱ��ִ�����²���
    while (!q.empty())
    {
        // ȡ�����ȶ���q�Ķ���Ԫ�أ������丳ֵ��c��s
        auto [c, s] = q.top();
        q.pop();
        // ��c��ӵ�ans��
        ans += c;
        // ��s�ĵ�һ���ַ�ɾ��
        s.erase(s.begin());
        // ���s��Ϊ�գ���s�ĵ�һ���ַ���s��Ϊpair�������ȶ���q��
        if (s.size())
        {
            q.push({s[0], s});
        }
    }
    // ���ans
    cout << ans;
    return 0;
}