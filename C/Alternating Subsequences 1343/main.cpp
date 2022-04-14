#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solve()
{
    int n;
    cin >> n;
    vector<int> myvec(n);
    vector<int> tracked;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        myvec[i] = x;
        if(tracked.size() == 0) tracked.push_back(x);
        else
        {
            if( (tracked.back() > 0 && x < 0) || (tracked.back() < 0 && x > 0) )
            {
                tracked.push_back(x);
            }
            else
            {
                if( (tracked.back() > 0 && x > 0 && x > tracked.back())
                || (tracked.back() < 0 && x < 0 && x > tracked.back()) )
                {
                    swap(x, tracked.back());
                }
            }
        }
    }
    /*for (auto elem : tracked) cout << elem << " ";
    cout << endl;*/
    long long ans = 0;
    for(auto elem : tracked)
    {
        ans += elem + 0ll;
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
}
