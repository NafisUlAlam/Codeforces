#include <bits/stdc++.h>

using namespace std;

int mod = 32768;
vector<int>ans(mod, INT_MAX);

void fillup()
{
    ans[0] = 0;
    ans[mod - 1] = 1;
    int curr = 0;
    int n = mod;
    while(n > 1)
    {
        n = n / 2;
        curr++;
    }
    //cout << curr << endl;
    for(int i = 1; i < mod; i = i * 2)
    {
        ans[i] = curr;
        curr--;
    }
    for(int i = mod - 1; i >= 0; i--)
    {
        if(ans[i] != INT_MAX) continue;
        curr = i;
        int f, s = 0;
        f = ans[i + 1] + 1;
        while(ans[curr] == INT_MAX)
        {
            curr = (curr * 2) % mod;
            s++;
        }
        s += ans[curr];
        ans[i] = min(f, s);
    }
    //for(auto elem : ans) cout << elem << " "; cout << endl;
}

void solve1661B()
{
   int n;
   cin >> n;
   for(int i = 0; i < n; i++)
   {
       int x;
       cin >> x;
       cout << ans[x] << " ";
   }
   cout << endl;

}

int main()
{
    fillup();
    solve1661B();
}
