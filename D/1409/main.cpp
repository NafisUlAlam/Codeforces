#include <bits/stdc++.h>
#define ll long long
using namespace std;

int sum(ll n)
{
    int res = 0;
    while(n > 0)
    {
        res += n % 10;
        n /= 10;
    }
    return res;
}

void solve()
{
    ll n, s;
    cin >> n >> s;
    if(sum(n) <= s) {cout << 0 << endl; return;}
    ll pw = 1, ans = 0;
    for(int i = 0; i <= 18; i++)
    {
        int digit = (n / pw) % 10;
        ll add = pw * ((10 - digit) % 10);
        n += add;
        ans += add;
        //cout << digit << " " << add << " " << n << endl;
        pw *= 10;
        if(sum(n) <= s) break;
    }
    cout << ans << endl;
}


int main()
{
    int t;
    cin >> t;
    while(t--) solve();
}
