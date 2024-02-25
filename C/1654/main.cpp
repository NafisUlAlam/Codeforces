#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n, sum = 0;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0, x; i < n; i++)
    {
        cin >> x;
        a[i] = x;
        sum += x;
    }
    sort(a.begin(), a.end());
    priority_queue<ll> pq;
    pq.push(sum);
    while(a.size() > 0 || pq.size() > 0)
    {
        if(pq.size() > 0)
        {
            ll x = pq.top();
            pq.pop();
            if(a.size() > 0)
            {
                ll y = a.back();
                if(x < y) break;
                else if (x == y) a.pop_back();
                else
                {
                    pq.push(x / 2);
                    pq.push((x + 1) / 2);
                }
            }
            else break;
        }
    }
    if(a.size() == 0 && pq.size() == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
}
