#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main()
{
    ull n, x;
    ull count = 0;
    cin >> n >> x;
    ull i;
    if (x > n * n ){
        cout << count; return 0;
    }
    for ( i = 1; i * i <= x; i++)
    {
        if(x % i == 0 && (x / i) <= n) count += 1;
    }
    if ((i -1) * (i - 1) == x)cout << count * 2 - 1;
    else cout << count * 2;
}
