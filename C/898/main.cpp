#include <bits/stdc++.h>

using namespace std;
bool comp(string& s1, string& s2)
{
    if(s1.size() == s2.size()) return s1 < s2;
    else return (int)s1.size() < (int)s2.size();
}
bool isSuffix(string& s1, string& s2)
{
    int n1 = s1.size();
    int n2 = s2.size();
    if(n1 >  n2) return false;
    for(int i = n1 - 1, j = n2- 1; i >= 0; i--, j--)
    {
        if(s1[i] != s2[j]) return false;
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    map<string, vector<string>> mp;
    for(int i = 1; i <= n; i++)
    {
        string name; int c;
        cin >> name >> c;
        for(int j = 1; j <= c; j++)
        {
            string number;
            cin >> number;
            mp[name].push_back(number);
        }
        //sort(mp[name].begin(), mp[name].end());

    }
    for(auto &elem : mp) sort(elem.second.begin(), elem.second.end(), comp);
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        auto it2 = it->second.begin();
        while(it2 != it->second.end())
        {
            //cout << " it2 : "<<*it2 <<endl;
            auto it3 = it2;
            it3++;
            while(it3 != it->second.end())
            {
                //cout << "it 3 : " << *it3 << endl;
                if(isSuffix(*it2, *it3)) {*it2 = "nomore"; break;}
                it3++;
            }
            it2++;
        }
    }
    cout << mp.size() << endl;
    for(auto elem : mp)
    {
        cout << elem.first << " ";
        int cnt = elem.second.size();
        for(auto e : elem.second)
        {
            if(e == "nomore") cnt--;
        }
        cout << cnt << " ";
        for(auto e : elem.second)
        {
            if(e == "nomore") continue;
            cout << e << " ";
        }
        cout << endl;
    }
}

int main()
{
    int t = 1;
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(t--)solve();
}
