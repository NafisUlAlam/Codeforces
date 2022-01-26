#include<bits/stdc++.h>
#define ll long long

using namespace std;



void solve()
{
    int n,k;
    cin >> n >> k;
    vector<int> myvecs[4];
    vector<int> sums[4];
    for(int i = 0; i < n; i++)
    {
        int t, a, b;
        cin >> t >> a >> b;
        myvecs[2 * a + b].push_back(t);
    }

    for(int i = 0; i < 4; i++)
    {
        sort(myvecs[i].begin(),myvecs[i].end());
        sums[i].push_back(0);
        for(auto it : myvecs[i])
        {
            sums[i].push_back(sums[i].back() + it);
        }
    }

    /*for(int i = 0; i < 4; i++)
    {
        cout << "i "<< i << endl;
        cout << "vector " << endl;
        for(auto elem : myvecs[i]) cout << elem << " ";
        cout << endl;
        cout << "sum "<< endl;
        for (auto elem : sums[i]) cout << elem << " ";
        cout << endl;
    }*/

    int ans = INT_MAX;
    for(int cnt = 0; cnt < min(k + 1, (int)sums[3].size()); cnt++)
    {
        if(k - cnt < sums[1].size() && k - cnt < sums[2].size())
        {
            ans = min (ans, sums[3][cnt] + sums[2][k - cnt]+ sums[1][k-cnt]);
        }
    }
    if(ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;

}


int main()
{
    int t = 1;
    //cin >> t;
    while(t--) solve();
}
