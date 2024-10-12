#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int N = 1e5 + 5;

int main()
{
    // 定义变量n，字符串s，字符串ans，优先队列q
    int n;
    string s, ans;
    // 定义一个优先队列q，其中pair的第一个元素为字符，第二个元素为字符串
    priority_queue<pair<char, string>> q;
    // 输入n
    cin >> n;
    // 循环n次，输入字符串s，并将s的第一个字符和s作为pair插入优先队列q中
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        q.push({s[0], s});
    }
    // 当优先队列q不为空时，执行以下操作
    while (!q.empty())
    {
        // 取出优先队列q的队首元素，并将其赋值给c和s
        auto [c, s] = q.top();
        q.pop();
        // 将c添加到ans中
        ans += c;
        // 将s的第一个字符删除
        s.erase(s.begin());
        // 如果s不为空，则将s的第一个字符和s作为pair插入优先队列q中
        if (s.size())
        {
            q.push({s[0], s});
        }
    }
    // 输出ans
    cout << ans;
    return 0;
}