#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(vector<ll>& a, ll left, ll right, ll x, vector<ll>& curr, ll pos, ll& cnt)
{
    //cout << "pos " << pos << endl;
    //for(auto elem : curr) cout << elem << " "; cout << endl;
    //cout << "count " << cnt << endl;
    if(pos == a.size()) return;

    for(ll i = pos; i < (ll)a.size(); i++)
    {
        curr.push_back(a[i]);
        if(curr.size() >= 2)
        {
            ll s = 0;
            ll n = curr.size();
            for(auto elem : curr) s += elem;
            ll mini = curr.front();
            ll maxi = curr.back();
            //cout << "size greater than 2 " << endl;
            //for(auto elem : curr) cout << elem << " "; cout << endl;
            //cout << " count in 2 " << cnt << endl;
            //cout << "sum " << s << endl;
            if(n >= 2 && s >= left && s <= right && maxi - mini >= x)
            {
                cnt++;
                //cout << "here we are increasing cnt " << cnt << endl;
                //for(auto elem : curr) cout << elem <<" "; cout << endl;
                //cout << s << endl;
            }
        }
        solve(a, left, right, x, curr, i + 1, cnt);
        curr.pop_back();
    }

}

void solve550B()
{
   ll n, l, r, x;
   cin >> n >> l >> r >> x;
   vector<ll> a(n);
   for(ll i = 0; i < n; i++) cin >> a[i];
   sort(a.begin(), a.end());
   vector<ll> curr;
   ll ans = 0;
   ll pos = 0;
   solve(a, l, r, x, curr, pos, ans);
   cout << ans << endl;
}

int main()
{
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t = 1;
   //cin >> t;
   while(t--)
   {
      solve550B();
   }
}
//  100 3 5 6 1 1 2 3
