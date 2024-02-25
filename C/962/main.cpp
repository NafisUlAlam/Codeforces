#include <bits/stdc++.h>
#define ll long long
using namespace std;

void sub(string& n, string& s, int i, ll& ans)
{
    if(i == n.size())
    {
        if(s.size() > 0 && (s[0] - '0') > 0)
        {
            ll curr = stoll(s);
            ll root = sqrt(curr);
            if(root * root == curr) ans = min(ans, (ll)(n.size() - s.size()));
        }
        return;
    }
    s.push_back(n[i]);
    sub(n, s, i + 1, ans);
    s.pop_back();
    sub(n, s, i + 1, ans);
}

void solve()
{
    string n, s;
    cin >> n;
    ll ans = 1e18;
    sub(n, s, 0, ans);
    ans = (ans == 1e18 ? -1 : ans);
    cout << ans << endl;
}

int main()
{
    solve();
}
