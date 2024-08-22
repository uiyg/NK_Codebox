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
                // i位置左边和j位置右边能组成一个回文串的最小距离
                ans += min(i, n - j);
        }
    }
    cout << ans;
}