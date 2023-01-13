#include <bits/stdc++.h>

using namespace std;

string findmin(string &a)
{
   int n = a.size();
   for(int i = 1; i <= n; i++)
   {
      if(n % i != 0) continue;
      string curr = a.substr(0, i);
      //cout << curr << endl;
      int j = i, k = 0;
      bool f = true;
      while(j < n)
      {
         if(a[j] == curr[k])
         {
            j++;
            k++;
            if(k == i) k = 0;
         }
         else
         {
            f = false;
            break;
         }
      }
      if(f == true) return curr;
   }
   return a;
}

void solve1473B()
{
   string s, t, ans;
   cin >> s >> t;
   string mins = findmin(s);
   string mint = findmin(t);
   //cout << mins << " " << mint << endl;
   if(mins.compare(mint) != 0) cout << -1 << endl;
   else
   {
      int p = s.size() / mins.size();
      int q = t.size() / mint.size();
      int lcm = (p * q) / __gcd(p, q);
      //cout << mins << " " << mint << " "<< lcm <<  endl;
      for(int i = 1; i <= lcm; i++)
      {
         for(int j = 0; j < mins.size(); j++) ans.push_back(mins[j]);
      }
      cout << ans << endl;
   }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve1473B();
}
