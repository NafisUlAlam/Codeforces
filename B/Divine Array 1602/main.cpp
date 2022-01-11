#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> myans(2001);
void solve()
{
    int n;
    cin >> n;
    vector<int> myvec(n);

    for(int i = 0; i < n; i++)
    {
        cin >> myvec[i];

    }
    myans[0] = (myvec);

    for(int i = 1; i <= n; i++)
    {
        map<int,int> mymap;
        for(int j = 0; j < n; j++)
        {
            mymap[myvec[j]]++;
        }
        for(int j = 0; j < n; j++)
        {
            myvec[j] = mymap[myvec[j]];
        }
        myans[i] = myvec;

    }
    int query;
    cin >> query;
    for(int i = 0; i < query; i++)
    {
        int x, k;
        cin >> x >> k;
        if(k > n) k = n;
        cout << myans[k][x-1] << endl;
    }


    /*for (auto elem : myans){
        for(auto e : elem) cout << e << " ";
        cout << endl;}*/


}




int main()
{
    int t;
    t = 1;
    cin >> t;
    while(t--) solve();
}
