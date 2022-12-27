#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> multiples(1005, -1);
void prefill()
{
   for(int i = 2; i <= 1000; i++)
   {
      for(int j = i * i; j <= 1000; j += i)
      {
         if(multiples[j] == -1)
         {
            multiples[j] = i;
         }
      }
   }
   //cout << multiples[437] << endl;
}

void solve1332B()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   set<int> mp;
   for(int i = 0; i < n; i++)
   {
      int num = a[i];
      //cout << num << " " << multiples[num] << endl;
      mp.insert(multiples[num]);
   }

   cout << mp.size() << endl;
   for(int i = 0; i < n; i++)
   {
      int curr = 0;
      {
         for(auto elem : mp)
         {
            curr++;
            if(a[i] % elem == 0)
            {
               cout << curr << " ";
               break;
            }
         }
      }
   }
   cout << endl;
}

int main()
{
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t = 1;
   prefill();
   cin >> t;
   while(t--)
   {
      solve1332B();
   }
}
