#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll check(ll mid, vector<ll>& a, ll c)
{
   for(auto e : a)
   {
      c -= mid * mid + 2ll * e * mid;
      if(c < 0) break;
   }
   //cout << mid << " " << ans << endl;
   if(c == 0) return 0;
   else if (c > 0) return 1;
   else return -1;
}

void solve1850E()
{
   ll n, c;
   cin >> n >> c;
   vector<ll> a(n);
   for(auto& e : a) {cin >> e; c -= e * e;}
   ll lo = 1, hi = 1e9, ans = -1;
   while(lo <= hi)
   {
      ll mid = (lo + hi) / 2;
      if(check(mid, a, c) == 1) lo = mid + 1;
      else if(check(mid, a, c) == -1) hi = mid - 1;
      else {ans = mid; break;}
   }
   cout << ans / 2 << endl;
}

int main()
{
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t = 1;
   cin >> t;
   while(t--) solve1850E();
}
