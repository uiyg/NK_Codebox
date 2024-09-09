#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 5;
const int N = 2e7 + 10;
int cnt = 0;
bool st[N];
ll prime[N];
// 使用埃拉托斯特尼筛法生成素数
void get_prime()
{
    for (int i = 2; i < N; i++)
    {
        if (!st[i])
            prime[cnt++] = i;  // 如果i是素数，将其添加到素数数组中
        for (int j = 0; prime[j] < N / i; j++)
        {
            st[prime[j] * i] = true;  // 标记prime[j]的倍数为非素数
            if (i % prime[j] == 0)
                break;  // 优化：当i能被prime[j]整除时跳出循环
        }
    }
}

// 解决问题的函数
void solve()
{   
    map<int, int> a;  // 用于存储输入数字的映射
    int n;
    cin >> n;  // 读取元素数量
    for (int i = 1; i <= n; i++)
    {
        int tamp;
        cin >> tamp;
        a[tamp] = 1;  // 在映射中标记输入的数字为存在
    }
    for (int i = 0; i < cnt; i++)
    {
        if (a[prime[i]] == 0)
        {
            cout << prime[i] << endl;  // 输出第一个不在输入中的素数
            break;
        }
    }
    // cout << a[2] ;  // 注释掉的调试输出
}

int main()
{
    int T = 1;
    cin >> T; // 如果有多组测试数据，取消此行注释
    get_prime();
    while (T--)
    {
        solve();
    }
    return 0;
}