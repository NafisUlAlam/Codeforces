#include<bits/stdc++.h>
#define ll long long
using namespace std;

int work(vector<int>& a)
{
    int n = a.size();
    int val[n + 1];
    for(int i = 1; i <= n; i++) val[i] = a[i - 1];
    if(n == 1) return 1;

    sort(val + 1,val + n + 1);

    int g = val[2] - val[1];
    for(int i = 3;i <= n;++i) {
        g = __gcd(g,val[i] - val[i - 1]);
    }

    int ans = 0;
    for(int i = 1;i <= n;++i) ans += (val[n] - val[i]) / g;

    for(int i = 1;i < n;++i)
        if(val[n] - g * i != val[n - i]) return ans + i;
    return ans + n;
}

int solve1902C(vector<int>& a)
{
//   ll n, ans = 0; int gcd = -1;
//   cin >> n;
//   vector<int> a(n);
//   for(auto &e : a) cin >> e;
    int n = a.size();
   sort(a.begin(), a.end());
   if(n == 1)
   {
      //cout << 1 << endl;
      return 1;
   }
   int gcd = a[1] - a[0]; ll ans = 0;
   for(int i = 1; i + 1 < n; i++) gcd = __gcd(gcd, (a[i + 1] - a[i]) );
   int last = -1;
   for(int i = n - 1; i - 1 >= 0; i--)
   {
      if(a[i] - gcd != a[i - 1])
      {
         last = a[i] - gcd;
         break;
      }
   }
   if(last == -1) last = a[n - 1] + gcd;
   //cout << gcd << " " << last << endl;
   for(int i = 0; i < n; i++)
   {
      ans += (max(last, a[n - 1]) - a[i]) / gcd;
      //cout << ans << endl;
   }
   ans += (max(last, a[n - 1]) - last) / gcd;
   return ans;
}


int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    int cnt = 1;
    while(cnt <= 1000)
    {
        int n = rand() % 20 + 1;
        vector<int> a;
        while(a.size() != n)
        {
            int curr = rand() % 101 - 50;
            if(find(a.begin(), a.end(), curr) == a.end()) a.push_back(curr);
        }
        //for(auto e : a) cout << e << " "; cout << endl;
        int correct = work(a);
        int my = solve1902C(a);
        if(correct != my)
        {
            cout << "correct " << correct << " my " << my << endl;
            cout << n << endl;
            for(int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
            break;
        }
        cnt++;
    }

}
