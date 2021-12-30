#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct stack
{
    vector<ll> s, sgcd = {0};
    void push(ll x)
    {
        s.push_back(x);
        sgcd.push_back(__gcd(sgcd.back(),x));
    }
    ll pop()
    {
        ll res = s.back();
        s.pop_back();
        sgcd.pop_back();
        return res;
    }
    bool empty()
    {
        return s.empty();
    }

    ll gcd()
    {
        return sgcd.back();
    }


    void display()
    {
        cout << "first stack : " ;
        for(auto elem : s) cout << elem <<" " ;
        cout << endl;
        cout << "gcd stack : " ;
        for (auto elem: sgcd) cout << elem <<" " ;
        cout << endl;
    }

};


::stack s1, s2;



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
    return __gcd(s1.gcd(), s2.gcd()) == 1;
}


int main()
{
    int n;
    cin >> n;
    vector<long long> myvec(n);
    for (int i = 0; i < n ; i++)
    {
        cin >> myvec[i];
    }

    int l = 0, result = INT_MAX;
    for (int r = 0; r < n; r++)
    {
        add(myvec[r]);
        //cout << "s1 : " ; s1.display();
        //cout << endl;
        //cout << "s2 : "; s2.display();
        while(good())
        {
            remove();
            l++;
        }

        if(l > 0)
        {
            result = min(result, r - l + 2);
            //cout << l << " " << r << endl;
        }

    }
    if (result == INT_MAX) cout << -1;
    else cout << result << endl;

}
