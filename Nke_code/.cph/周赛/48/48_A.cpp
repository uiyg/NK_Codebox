#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int maxx =max(a, max(b, c));
    int sun =3*maxx-a-b-c;
    cout << sun;
}