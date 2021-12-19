#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

int main()
{
    ull t;
    cin >> t;
    while(t--)
    {
        ull n, m , x;
        cin >> n >> m >> x;

        ull col = (x - 1) / n;
        ull firstitem = 1 + col * n;
        ull diff = x - firstitem;
        ull rowterms = diff * m;
        ull otherterms = (x + n - 1) / n;
        cout << rowterms + otherterms << endl;
    }
}
