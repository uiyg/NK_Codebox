#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,ans=0;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        if(n%2==0||n%3==0||n%5==0){
            return;
        }
        ans++;
    }
    cout<<ans<<endl;
}

int main(){
    int T=1;
    // cin >> T;
    while(T--){
        solve();
    }
}