#include <bits/stdc++.h>
long long INF = 1e18;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int,long long> mymap;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mymap[x]++;
    }

    long long ans, mini, maxi, sz;
    sz = mymap.size();
    mini = INF; maxi = 0;
    for(auto elem : mymap)
    {
        mini = min(mini, elem.second);
        maxi = max(maxi, elem.second);
    }
    //cout << mini << " " << maxi << " " << sz << endl;
    if( (sz < mini && sz < maxi) || (sz > mini && sz < maxi) ||
        (mini == sz && sz < maxi) )cout << sz << endl;
    else if( (mini < sz && maxi < sz) ) cout << maxi << endl;
    else cout << maxi - 1 << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
}
