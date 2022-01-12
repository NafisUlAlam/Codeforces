#include<bits/stdc++.h>
using namespace std;


void solve()
{
    int n;
    cin >> n;
    vector<int> myvec(n);
    for(int i = 0; i < n;i++)
    {
        cin >> myvec[i];
    }
    if(n % 2 == 0)
    {
        cout << "YES" << endl; return;
    }
    else
    {
        for(int i = 0; i < n - 1; i++)
        {
            if(myvec[i] >= myvec[i + 1])
            {
                cout << "YES" << endl;
                return;
            }
        }
        cout << "NO" << endl;
        return;
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
}
