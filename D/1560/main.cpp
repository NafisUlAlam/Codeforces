#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> twos;
void pre()
{
   ll i = 1;
   for(i = 1; i <= 1e18; i *= 2)
   {
      twos.push_back(i);
   }
   //for(auto elem : twos) cout << elem << " "; cout << endl;
}

void solve1560D()
{
   int n;
   cin >> n;
   string input = to_string(n);
   int mini = INT_MAX;
   for(int i = 0; i < twos.size(); i++)
   {
      string curr = to_string(twos[i]);
      int currsz = curr.size();
      int insz = input.size();
      int ini = 0, curri = 0, ans = 0;
      while(curri < currsz)
      {
         if(curr[curri] != input[ini])
         {
            ans++;
            ini++;
         }
         else
         {
            curri++;
            ini++;
         }

         if(ini >= insz) break;
      }

      //cout << curr << " " << curri << endl;
      if(curri < currsz) ans +=  currsz - curri;
      else if(ini < insz) ans += insz - ini;
      if(mini > ans)
      {
         mini = ans;
         //cout << curr << " " << mini << endl;
      }
   }
   cout << mini << endl;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    pre();
    int t;
    cin >> t;
    while(t--) solve1560D();
}
