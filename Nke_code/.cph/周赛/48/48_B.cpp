#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    s = ' ' + s;
    int ans = 0, n = s.size();
    for (int i = 1; i < s.size(); i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            if (s[i] != s[j])
                // iλ����ߺ�jλ���ұ������һ�����Ĵ�����С����
                ans += min(i, n - j);
        }
    }
    cout << ans;
}