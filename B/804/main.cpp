#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(vector<ll>& powers, ll mod)
{
    string s;
    cin >> s;
    ll cnt = 0, ans = 0;
    vector<ll> a;
    for(int i = 0; i < (int)s.size(); i++) if(s[i] == 'a') cnt++;
    for(int i = (int)s.size() - 1; i >= 0; i--)
    {
        if(s[i] == 'a') cnt--;
        else a.push_back(cnt);
    }
    //for(auto e : a) cout << e << " "; cout << endl;
    for(auto e : a) ans = (ans + powers[e] - 1) % mod;
    cout << ans << endl;
}


int main()
{
    vector<ll> powers(1e6 + 10, 1);
    ll mod = 1e9 + 7;
    for(int i = 1; i < 1e6 + 10; i++)
    {
        powers[i] = ( (powers[i - 1]) % mod * (2ll % mod) ) % mod;
    }
    solve(powers, mod);
}
