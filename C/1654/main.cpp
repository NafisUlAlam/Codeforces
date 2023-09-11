#include <bits/stdc++.h>
#define ll long long
using namespace std;

void dfs(ll sum, map<ll, ll>& cnt)
{
    if(cnt[sum] > 0 || sum == 1)
    {
        cnt[sum]--;
        return;
    }
    dfs(sum / 2, cnt);
    dfs((sum + 1) / 2, cnt);

}

void solve()
{
    ll n, sum = 0;
    map<ll, ll> cnt;
    cin >> n;
    for(int i = 1, x; i <= n; i++)
    {
        cin >> x;
        cnt[x]++;
        sum += x;
    }

    dfs(sum, cnt);
    for(auto e : cnt)
    {
        if(e.second != 0) {cout << "NO" << endl; return;}
    }
    cout << "YES" << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
}
