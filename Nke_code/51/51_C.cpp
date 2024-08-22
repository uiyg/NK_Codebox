#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 110;
int main()
{
    int x, y, t, a, b, c;
    cin >> x >> y >> t >> a >> b >> c;
    int z = 100 - x;
    double solve = z * 1.0 / b;
    if (a > y)
        solve = min(solve, (z * 1.0) / (a - y));
    if (x > t)
        solve = min(solve, (x - t) * 1.0 / y + (100 - t) * 1.0 / c);

    else
        solve = min(solve, (z * 1.0) / c);
    printf("%.9lf", solve);
    return 0;
}