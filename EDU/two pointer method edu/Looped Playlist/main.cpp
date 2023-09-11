#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    ll n, sum;
    cin >> n >> sum;
    vector<ll> a(n);
    ll mysum = 0;
    for(ll i = 0; i < n; i++)
    {
        int e;
        cin >> e;
        a[i] = e;
        mysum += e;
    }
    for(int i = 0; i < n; i++) a.push_back(a[i]);
    ll div = sum / mysum;
    ll need = sum % mysum;
    if(need == 0)
    {
        cout << 1 << " " << div * n << endl;
        return;
    }
    ll r = 0, l = 0, curr = 0, lans = -1, ans = INT_MAX;
    for(r = 0; r < 2 * n; r++)
    {
        curr += a[r];
        //cout << curr << endl;
        while(curr >= need)
        {
            if(r - l + 1 < ans)
            {
                ans = r - l + 1;
                lans = l;
            }
            curr -= a[l];
            l++;
        }
    }
    cout << (lans % n) + 1 << " " << div * n + ans << endl;

}

int main()
{
    // 6 4 1 1 1 1 1 8
    int t = 1;
    while(t--) solve();
}
