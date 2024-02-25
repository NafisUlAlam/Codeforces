#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> divisors(1e5 + 10);
vector<int> cnt(1e5 + 10, 0);
vector<int> tmp(1e5 + 10, 0);
void pre()
{
    int maxi = 0, total;
    for(int i = 1; i < divisors.size(); i++)
    {
        for(int j = i; j < divisors.size(); j += i) divisors[j].push_back(i);
    }
    for(int i = 1; i < divisors.size(); i++) sort(divisors[i].rbegin(), divisors[i].rend());
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& e : a) cin >> e;
    sort(a.begin(), a.end());

    ll ans = 0, rem = n;

    for(auto e : a)
    {
        rem--;
        ll val;
        for(auto d : divisors[e])
        {
            val = cnt[d] - tmp[d];
            for(auto d2 : divisors[d])
            {
                tmp[d2] += val;
            }
            ans += d * 1ll * val * rem;
        }

        for(auto d : divisors[e])
        {
            for(auto d2 : divisors[d]) tmp[d2] = 0;
        }

        for(auto d : divisors[e]) cnt[d]++;

    }
    cout << ans << endl;
    for(int i = 0; i < cnt.size(); i++) cnt[i] = 0;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    pre();
    int t = 1;
    cin >> t;
    while(t--) solve();
}
