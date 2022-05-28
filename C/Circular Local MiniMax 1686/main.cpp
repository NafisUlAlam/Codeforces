#include<bits/stdc++.h>
#define ll long long
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;


const ll MAXAI =(ll) 1e12;
const int INF = (int) 1e9;
const int mod = (int)1e9 + 7;
const int maxn = (int) 1e5 + 10;




void solve6()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    sort(a.begin(), a.end());
    vector<int> maxi, mini;

    for(int i = 0; i < (n + 1) / 2; i++) mini.push_back(a[i]);
    for(int i = (n + 1) / 2; i < n; i++) maxi.push_back(a[i]);

    vector<int> ans(n + 1);
    vector<bool> where(n + 1);
    int last = -1;
    for(int i = 2; i <= n; i += 2)
    {
        ans[i] = maxi[(i - 2) / 2];
        where[i] = true;
        last = i;
    }

    for(int i = 1; i <= n; i += 2)
    {
        ans[i] = mini[(i - 1) / 2];
        where[i] = false;
    }

    if(last == n) last -= 2;
    bool cur = true;

    for(int i = 2; i <= last; i+= 2)
    {
        if(ans[i - 1] < ans[i] && ans[i] > ans[i + 1]) cur &= true;
        else cur &= false;
    }
    if(ans[n - 1] < ans[n] && ans[n] > ans[1]) cur &= true;
    else cur &= false;
    if(ans[n] > ans[1] && ans[1] < ans[2]) cur &= true;
    else cur &= false;
    if(cur == false || (where[1] == false && where[n] == false))
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}




int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve6();

}


