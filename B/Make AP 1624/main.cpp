#include<bits/stdc++.h>

#define ll long long
using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    int ga, gb, gc;
    ga = 2 * b - c;
    gc = 2 * b - a;
    gb = a + c;

    if((ga > 0 && ga % a ==0 )||(gc > 0 && gc % c == 0) ||
        (gb % 2 == 0 && (gb / 2)% b == 0 && (gb / 2) > 0))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

}


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }

}
