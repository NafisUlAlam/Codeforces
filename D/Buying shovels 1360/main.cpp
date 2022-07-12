#include<bits/stdc++.h>
using namespace std;

void solve1360D()
{
   int n, k;
   cin >> n >> k;
   vector<int> divisors;
   for(int i = 1; i * i<= n; i++)
   {
      if(n % i == 0)
      {
         divisors.push_back(i);
         if(i != n / i) divisors.push_back(n / i);
      }
   }
   sort(divisors.begin(), divisors.end());
   //for(auto elem : divisors) cout << elem << " "; cout << endl;
   if(binary_search(divisors.begin(), divisors.end(), k))
   {
      cout << n / k << endl;
   }
   else
   {
      int indx = lower_bound(divisors.begin(), divisors.end(), k) - divisors.begin();
      k = divisors[--indx];
      cout << n / k << endl;
   }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int ans = INT_MAX;
    for(int i = 1; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            if(i <= k)
            {
                ans = min(ans, n / i);
            }
            if(n / i <= k)
            {
                ans = min(ans, i);
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
    {
       solve1360D();
    }
}
