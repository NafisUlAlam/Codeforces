#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solve()
{
    int n , k;
    cin >> n >> k;
    vector<ll> myvec(n);
    map<ll,ll> mymap;
    for(auto &x : myvec)
    {
        cin >> x;
        if(x % k != 0)mymap[ k - (x % k)]++;
        else mymap[0]++;
    }
    /*for (auto elem : mymap) cout <<elem.first<<" : "<< elem.second << " ";
    cout << endl;*/
    ll max = -1;
    ll ind = - 1;
    for(auto elem : mymap)
    {
        if(elem.first != 0)
        {
            if(elem.second >= max)
            {
                ind = elem.first;
                max = elem.second;
            }
        }
    }
    //cout <<ind <<" : "<< max << endl;
    if(ind == -1) {cout << 0 << endl; return;}
    ll ans = k * 1ll * (max - 1);
    ans += ind + 1;
    cout << ans << endl;
}



int main()
{
    int t;
    cin >> t;
    while(t--) solve();
}
