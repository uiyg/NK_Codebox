#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    s1 = " " + s1;
    s2 = " " + s2;
    vector<int> a;
    int ans = 0;
    if (n == 1)
    {
        cout << -1;
        return 0;
    }

    for (int i = 1; i < n; i++)
    {

        if (s1[i] != s2[i])
        {
            s1[i] = s2[i];
            if (s1[i + 1] == '1')
                s1[i + 1] = '0';
            else
                s1[i + 1] = '1';
            // cout << s1<<' '<<i<<endl;
            a.push_back(i);
            ans++;
        }
    }
    if (s1 != s2)
    {
        cout << -1;
        return 0;
    }
    cout << ans << endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << ' ' << a[i] + 1 << endl;
    }

    return 0;
}