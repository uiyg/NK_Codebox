#include <bits/stdc++.h>
#define ll long long
using namespace std;
// 不知道为什么D大一些？
ll gcd(ll a, ll b)
{
    while (b != 0)
    {
        ll tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}
int main()
{
    string s;
    cin >> s;
    ll aa=0,b;
    cin >> b;
    for(auto a:s){
        aa *= 10;
        aa+=a-'0';
        aa %= b;
    }
    cout << gcd(aa,b) << endl;
    return 0;
}
