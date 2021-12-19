#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> myvec(n);
    vector<int> myans(n,0);
    unordered_set<int> uns;


    for(int i = 0 ; i < n; i++)
    {
        cin >> myvec[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if(uns.find(myvec[i]) == uns.end())
        {
            if (i < n - 1)myans[i] = myans[i+1] + 1;
            else myans[i] = 1;
        }
        else myans[i] = myans[i+1];
        uns.insert(myvec[i]);
    }
    //for (auto elem : myans) cout << elem << " ";

   for (int i = 0; i < m; i++)
   {
       int l;
       cin >> l;
       cout << myans[l - 1] << endl;
   }
}
