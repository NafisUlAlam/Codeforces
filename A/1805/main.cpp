#include <bits/stdc++.h>

using namespace std;

void solve()
{
    bitset<10> ans;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        bitset<10> curr(x);
        ans ^= x;
    }
    int f = 0, mul = 1;
    for(int i = 0; i < 9; i++)
    {
        f += ans[i] * mul;
        mul *= 2;
        //cout << f << endl;
    }
    if(n % 2 == 1 || (n % 2 == 0 && ans == 0)) cout << f << endl;
    else cout << -1 << endl;
}


int main()
{
    int t; cin >> t;
    while(t--)solve();
    return 0;
}
