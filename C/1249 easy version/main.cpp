#include<bits/stdc++.h>
using namespace std;

vector<int> a;
void prefill()
{
   for(int i = 1; i <= (int) 19683; i++)
   {
      int curr = i;
      bool ok = true;
      while(curr > 0)
      {
         int rem = curr % 3;
         if(rem == 2)
         {
            ok = false; break;
         }
         curr /= 3;
      }
      if(ok == true) a.push_back(i);
   }

   //for(int i = 0; i < a.size(); i++) cout << a[i] << " "; cout << endl;
}

void solve()
{
   int n;
   cin >> n;
   int idx = lower_bound(a.begin(), a.end(), n) - a.begin();
   cout << a[idx] << endl;
}

int main()
{

   ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
   int t = 1;
   prefill();
   cin >> t;
   while(t--)
   {
      solve();
   }
}
