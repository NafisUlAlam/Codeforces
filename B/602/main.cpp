#include <bits/stdc++.h>

using namespace std;

struct stak
{
    vector<int> maxi, mini, a;
    void psh(int x)
    {
        a.push_back(x);
        if(maxi.size() == 0) maxi.push_back(x);
        else maxi.push_back(max(x, maxi.back()));
        if(mini.size() == 0) mini.push_back(x);
        else mini.push_back(min(x, mini.back()));
    }
    int po()
    {
        int x = INT_MIN;
        if(a.size() > 0)
        {
            x = a.back();
            a.pop_back();
            maxi.pop_back();
            mini.pop_back();
        }
        return x;
    }
    int getmaxi()
    {
        if(a.size() == 0) return INT_MIN;
        //cout << maxi.back() << endl;
        return maxi.back();
    }
    int getmini()
    {
        if(a.size() == 0) return INT_MAX;
        //cout << mini.back() << endl;
        return mini.back();
    }
};

void add(int x, stak& s1) {s1.psh(x);}

int getmini(stak& s1, stak& s2)
{
    return min(s1.getmini(), s2.getmini());
}

int getmaxi(stak& s1, stak& s2)
{
    return max(s1.getmaxi(), s2.getmaxi());
}

bool good(stak& s1, stak& s2)
{
    //cout << getmaxi(s1, s2) << " " << getmini(s1, s2) << endl;
    return getmaxi(s1, s2) - getmini(s1, s2) <= 1;
}

void rem(stak& s2, stak& s1)
{
    if(s2.a.size() == 0)
    {
        while(s1.a.size() > 0)
        {
            int x = s1.po();
            //cout << x << " is inserted into s2 and size of s1 : " << s1.a.size() << endl;
            s2.psh(x);
        }
    }
    s2.po();
}

void solve()
{
    int n, ans = 0, l = 0, r = 0;
    cin >> n;
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    stak s1, s2;
    for(r = 0; r < n; r++)
    {
        add(a[r], s1);
        //cout << l << " " << r << endl;
        while(!good(s1, s2)) {rem(s2, s1); l++;}
        ans = max(ans, r - l + 1);
    }
    cout << ans << endl;
}

int main()
{
    solve();
}
