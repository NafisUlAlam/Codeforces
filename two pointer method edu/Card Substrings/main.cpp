#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<int> a(26, 0);
    // s = abacaba, t = abc
    for(int i = 0; i < m; i++) a[t[i] - 'a']++;
    int l = 0, r = 0;
    ll ans = 0;
    for(r = 0; r < n; r++)
    {
        a[s[r] - 'a']--;
        if(a[s[r] - 'a'] >= 0)
        {
            ans += (r - l + 1);
            continue;
        }
        else
        {
            while(a[s[r] - 'a'] < 0)
            {
                a[s[l] - 'a']++;
                l++;
            }
            if(r >= l) ans += r - l + 1;
        }
    }
    cout << ans << endl;
}

int main()
{
    solve();
}
