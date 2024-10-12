#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

// 函数solve用于解决问题
void solve()
{
    // 初始化变量，n为字符串长度，cnt为计数器
    int n, cnt = 0; 
    cin >> n; // 输入字符串长度
    // 创建一个向量v用于存储后缀和
    vector<int> v(n + 2); 
    string s;
    cin >> s; // 输入字符串
    // 在字符串前面添加一个'0'，方便索引
    s = '0' + s; 
    // 创建一个映射mp用于记录已经出现的字符
    map<char, int> mp; 
    // 从字符串末尾开始遍历
    for (int i = n; i >= 1; i--) 
    {
        // 如果字符s[i]没有在mp中出现
        if (!mp[s[i]]) 
        {
            // 更新后缀和
            v[i] = v[i + 1] + 1; 
            // 计数器加一
            cnt++; 
            // 将字符s[i]标记为已经出现
            mp[s[i]] = 1; 
        }
        else
        {
            // 如果字符s[i]已经出现，直接复制前一个值
            v[i] = v[i + 1]; 
        }
    }
    // 清空mp，方便后续使用
    mp.clear(); 
    // 初始化答案变量
    int ans = 0; 
    // 从字符串开始遍历
    for (int i = 1; i <= n; i++) 
    {
        // 如果字符s[i]没有在mp中出现
        if (!mp[s[i]]) 
        {
            // 将后缀和添加到答案中
            ans += v[i + 1]; 
            // 将字符s[i]标记为已经出现
            mp[s[i]] = 1; 
        }
    }
    // 输出最终答案
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