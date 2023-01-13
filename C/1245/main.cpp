#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll mod = 1e9 + 7;
vector<ll> fib(1e5 + 10, 0);

void prefill()
{
   fib[1] = 1;
   fib[2] = 2;
   for(int i = 3; i < (int) 1e5 + 10; i++)
   {
      fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
   }
   //cout << fib[6] << endl;
}
void solve1245C()
{
    string s;
    cin >> s;
    ll n = s.size();
    for(ll i = 0; i < n; i++)
    {
        if(s[i] == 'm' || s[i] == 'w')
        {
        cout << 0 << endl;
        return;
        }
    }

    ll ans = 1;
    for(ll i = 0; i < n; i++)
    {
        ll j = i;
        //cout << "hi" << endl;
        if(s[j] == 'u' || s[j] == 'n')
        {
            if(s[j] == 'u')
            {
                while(j < n && s[j] == 'u') j++;
                ll total = j - i;
                ans = (ans * fib[total]) % mod;
            }
            else if(s[j] == 'n')
            {
                while(j < n && s[j] == 'n') j++;
                ll total = j - i;
                ans = (ans * fib[total]) % mod;
            }
            i = j - 1;
        }
        else continue;
    }
    cout << ans << endl;
}

int main()
{
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   prefill();
   int t = 1;
   //cin >> t;
   while(t--)
   {
      solve1245C();
      //solve1762B();
      //solve1694DfromPC();
   }
}
