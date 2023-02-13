#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct stack
{
    vector<ll> s, smin, smax;
    void push(ll x)
    {
        s.push_back(x);
        if(smin.size() == 0) smin.push_back(x);
        else smin.push_back(min(smin.back(), x));

        if(smax.size() == 0) smax.push_back(x);
        else smax.push_back(max(smax.back(), x));
    }
    ll pop()
    {
        if(s.size() == 0) return -1;
        ll p = s.back();
        s.pop_back();
        smin.pop_back();
        smax.pop_back();
        return p;
    }

    bool empty()
    {
        return s.size() == 0;
    }

    ll mini()
    {
        if(s.size() == 0) return INT_MAX;
        return smin.back();
    }
    ll maxi()
    {
        if(s.size() == 0) return INT_MIN;
        return smax.back();
    }
    void clear()
    {
        s.clear();
        smin.clear();
        smax.clear();
    }
    void print()
    {
        cout << "s ";
        for(auto elem : s) cout <<  elem << " "; cout << endl;
        cout << "smin ";
        for(auto elem : smin) cout <<  elem << " "; cout << endl;
        cout << "smax ";
        for(auto elem : smax) cout <<  elem << " "; cout << endl;
    }
};

::stack s1, s2;

void add(ll x)
{
    s1.push(x);
}

void remove()
{
    if(s2.empty())
    {
        while(!s1.empty())
        {
            ll p = s1.pop();
            s2.push(p);
        }
    }
    s2.pop();
}

ll getmini()
{
    return min(s1.mini(), s2.mini());
}

ll getmaxi()
{
    return max(s1.maxi(), s2.maxi());
}

void solve()
{
    s1.clear(); s2.clear();
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll l = 0, r = 0;
    bool found = false;
    for(r = 0; r < n; r++)
    {
        add(a[r]);
        //cout << "s1 ";s1.print();
        //cout << "s2 ";s2.print();
        if(r <= 2) continue;
        ll left = a[l];
        ll right = a[r];
        ll mini = getmini();
        ll maxi = getmaxi();
        //cout << mini << " " << maxi << endl;
        if(left != mini && left != maxi && right != mini && right != maxi)
        {
            found = true;
            break;
        }
        if(left == mini || left == maxi)
        {
            ::remove();
            l++;
            continue;
        }
        else if (right == maxi || right == mini) continue;
    }

    if(found == false) cout << -1 << endl;
    else cout << l + 1 << " " << r + 1 << endl;
}

void solve2()
{
    int n;
    cin >> n;
    vector<int> a(n), ind(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        ind[a[i]] = i;
    }
    int currmini = 0, currmaxi = n - 1, left = 0, right = n - 1;
    bool flag = false;
    while(left <= right)
    {
        //cout << ind[currmini] << " " << ind[currmaxi] << endl;
        if(currmini > currmaxi )
        {
            flag = false;
            break;
        }
        if(ind[currmini] > left && ind[currmini] < right)
        {
            if(ind[currmaxi] > left && ind[currmaxi] < right)
            {
                flag = true;
                break;
            }
            else if(ind[currmaxi] == right)
            {
                right--;
                currmaxi--;
            }
            else if(ind[currmaxi] == left)
            {
                left++;
                currmaxi--;
            }
        }
        else if(ind[currmini] == left)
        {
            if(ind[currmaxi] > left && ind[currmaxi] < right)
            {
                left++;
                currmini++;
            }
            else if(ind[currmaxi] == right)
            {
                right--;
                currmaxi--;
                left++;
                currmini++;
            }
            else if(ind[currmaxi] == left)
            {
                left++;
                currmaxi--;
                currmini++;
            }

        }
        else if (ind[currmini] == right)
        {
            if(ind[currmaxi] > left && ind[currmaxi] < right)
            {
                currmini++;
                right--;
            }
            else if(ind[currmaxi] == right)
            {
                right--;
                currmaxi--;
                currmini++;
            }
            else if(ind[currmaxi] == left)
            {
                left++;
                currmaxi--;
                currmini++;
                right--;
            }

        }
    }
    if(flag) cout << left + 1 << " " << right + 1 << endl;
    else cout << -1 << endl;
}
int main()
{

    int t;
    cin >> t;
    while(t--) solve2();
}
