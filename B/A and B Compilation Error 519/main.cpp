#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    unordered_map<int,int> initial;
    unordered_map<int,int> f;
    unordered_map<int,int> s;
    int nu1, nu2;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        initial[x]++;
    }

    for(int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        f[x]++;
    }
    for(int i = 0; i < n - 2; i++)
    {
        int x;
        cin >> x;
        s[x]++;
    }

    for(auto x : initial)
    {
        if(f.count(x.first) == 0) nu1 = x.first;
        else if(f.count(x.first) > 0 && initial[x.first] != f[x.first]) nu1 = x.first;
    }
    for(auto x : f)
    {
        if(s.count(x.first) == 0) nu2 = x.first;
        else if(s.count(x.first) > 0 && f[x.first] != s[x.first]) nu2 = x.first;
    }
    cout << nu1 << endl << nu2;
}
