#include <bits/stdc++.h>
#define ll long long


using namespace std;

struct stack
{
    vector<ll> s, smin ={LLONG_MAX}, smax = {LLONG_MIN};
    void push(ll x)
    {
        s.push_back(x);
        smin.push_back(::min(smin.back(),x) );
        smax.push_back(::max(smax.back(),x) );
    }

    ll pop()
    {
        if(empty()) return -1;
        ll res = s.back();
        s.pop_back();
        smin.pop_back();
        smax.pop_back();
        return res;
    }
    bool empty()
    {
        return s.empty();
    }

    ll min()
    {
        return smin.back();
    }
    ll max()
    {
        return smax.back();
    }


};

::stack s1, s2;


ll k;


void add(ll x)
{
    s2.push(x);
}

void remove()
{
    if(s1.empty())
    {
        while(!s2.empty()) s1.push(s2.pop());
    }
    s1.pop();
}

bool good()
{
    ll mn = min(s1.min(),s2.min());
    ll mx = max(s1.max(),s2.max());
    return mx - mn <= k;
}


int main()
{
    int n;
    cin >> n >> k;
    vector<ll> myvec(n);


    for(int i = 0; i < n; i++)
    {
        cin >>myvec[i];
    }
    int l = 0;
    ll result = 0;
    for(int r = 0; r < n; r++)
    {
        add(myvec[r]);
        while(!good())
        {
            remove();
            l++;
        }
        result += r - l + 1;
    }

    cout << result << endl;




}
