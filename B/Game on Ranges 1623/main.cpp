#include <bits/stdc++.h>

using namespace std;

bool mysort(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b)
{
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<pair<int,int>> myvec(n);
        vector<pair<int,pair<int,int>>> myvecsorted(n);
        vector<bool> picked(n + 1,false);

        for(int i = 0; i < n; i++)
        {
            int l, r;
            cin >> l >> r;
            myvec[i] = {l,r};
            myvecsorted[i] = {l,{r,-1}};
        }
        sort(myvecsorted.begin(),myvecsorted.end(),mysort);
        for(int i = n - 1; i >= 0; i--)
        {
            if(myvecsorted[i].first == myvecsorted[i].second.first)
            {
                myvecsorted[i] = {myvecsorted[i].first,{myvecsorted[i].first,myvecsorted[i].first}};
                picked[myvecsorted[i].first] = true;

            }
            else
            {
                unordered_set<int> myset;
                for(int j = myvecsorted[i].first; j <= myvecsorted[i].second.first; j++)
                {
                    if(picked[j] == false)myset.insert(j);
                }

                if(picked[*myset.begin()] == false)
                {
                    picked[*myset.begin()] = true;
                    myvecsorted[i] = {myvecsorted[i].first, {myvecsorted[i].second.first,*myset.begin()}};
                }

            }
            cout << myvecsorted[i].first <<" " << myvecsorted[i].second.first << " "<<myvecsorted[i].second.second << endl;
        }

    }
}
