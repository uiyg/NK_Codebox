#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    //优先队列,greater<double>表示小根堆
    priority_queue<double, vector<double>, greater<double>> q;

    for (int i = 0; i < n; i++)
    {
        long long x, y, r;
        cin >> x >> y >> r;
        if ((x * x + y * y) < (r * r))
        {
            long long a = x * x + (y * y);
            double sq = sqrt(a);
            sq = r - sq;
            //acos(-1)表示π
            sq = sq * acos(-1) * r * r;
            q.push(sq);
            // mp.insert(r,{x,y});
        }
    }
    double ans = 0;

    if (q.size() <= k)
        printf("%.10f\n", ans);
    else
    {
        while (q.size() > k)
        {
            auto t = q.top();
            //                 cout<<t<<'\n';
            q.pop();
            ans += t;
            //                  printf("%.8f\n",ans);
        }
        printf("%.10f\n", ans);
    }
    return 0;
}