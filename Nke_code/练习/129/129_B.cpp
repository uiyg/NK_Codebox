#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

ll ksm(ll a,ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res*a%MOD;
        a = a*a%MOD;
        b>>=1;
    }
    return res;
}
void solve()
{
    int n, m;
    cin>>n>>m;
    ll ans1, ans;
    ans1 = ksm(2, m)-2;
    ans= ksm((ans1+MOD)%MOD,n);
    cout<<ans<<endl;
}

int main()
{
    int T = 1;
    cin>>T;
    while(T--){
        solve();
    }
}