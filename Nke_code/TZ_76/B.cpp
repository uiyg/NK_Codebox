#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

// ����solve���ڽ������
void solve()
{
    // ��ʼ��������nΪ�ַ������ȣ�cntΪ������
    int n, cnt = 0; 
    cin >> n; // �����ַ�������
    // ����һ������v���ڴ洢��׺��
    vector<int> v(n + 2); 
    string s;
    cin >> s; // �����ַ���
    // ���ַ���ǰ�����һ��'0'����������
    s = '0' + s; 
    // ����һ��ӳ��mp���ڼ�¼�Ѿ����ֵ��ַ�
    map<char, int> mp; 
    // ���ַ���ĩβ��ʼ����
    for (int i = n; i >= 1; i--) 
    {
        // ����ַ�s[i]û����mp�г���
        if (!mp[s[i]]) 
        {
            // ���º�׺��
            v[i] = v[i + 1] + 1; 
            // ��������һ
            cnt++; 
            // ���ַ�s[i]���Ϊ�Ѿ�����
            mp[s[i]] = 1; 
        }
        else
        {
            // ����ַ�s[i]�Ѿ����֣�ֱ�Ӹ���ǰһ��ֵ
            v[i] = v[i + 1]; 
        }
    }
    // ���mp���������ʹ��
    mp.clear(); 
    // ��ʼ���𰸱���
    int ans = 0; 
    // ���ַ�����ʼ����
    for (int i = 1; i <= n; i++) 
    {
        // ����ַ�s[i]û����mp�г���
        if (!mp[s[i]]) 
        {
            // ����׺����ӵ�����
            ans += v[i + 1]; 
            // ���ַ�s[i]���Ϊ�Ѿ�����
            mp[s[i]] = 1; 
        }
    }
    // ������մ�
    cout << ans + cnt << endl; 
}
int main()
{
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}