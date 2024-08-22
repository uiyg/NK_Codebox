#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
int a[N], n;

// 检查是否可以将数组中的每个元素都除以x，直到不能再除为止，最后得到的集合大小是否为x
int chek(int x)
{
    set<int> q;
    for (int i = 1; i <= n; i++)
    {
        int m = a[i];
        // 将m除以x，直到不能再除为止
        while (m >= x && m)
            m /= 2;
        // 如果集合中已经存在m，则将m继续除以2，直到不再存在
        while (q.count(m) && m)
            m /= 2;
        q.insert(m);
    }
    // 返回集合的大小是否为x
    return q.size() == x;
}
void solve()
{
    // 输入数组长度
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        // 输入数组元素
        cin >> a[i];
    }
    // 二分查找
    int l = 1, r = n, ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l)/ 2;
        // 如果可以除以mid，则更新答案，并继续查找更大的mid
        if (chek(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        // 否则，继续查找更小的mid
        else
            r = mid - 1;
    }
    // 输出答案
    cout << ans << endl;
}
int main()
{
    int T;
    // 输入测试用例数量
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}