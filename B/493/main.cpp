#include <bits/stdc++.h>
#define ll long long
using namespace std;
int comp(vector<int>& s1, vector<int>& s2)
{
    int n = s1.size(), m = s2.size(), i, j;
    for(i = 0, j = 0; i < n && j < m; i++, j++)
    {
        if(s1[i] > s2[j]) return 1;
        else if(s1[i] < s2[j]) return -1;
    }
    if(i == n && j == m) return 0;
    else if(i == n) return -1;
    else return 1;
}
void solve()
{
    ll n, x, cnt1 = 0, cnt2 = 0, last = -1;
    vector<int> ff, ss;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        if(x > 0)
        {
            ff.push_back(x);
            cnt1 += x;
            last = 1;
        }
        else
        {
            ss.push_back(-x);
            cnt2 += -x;
            last = 2;
        }
    }
    //cout << ff << " " << ss << " " << last << endl;
    if(cnt1 != cnt2)
    {
        if(cnt1 > cnt2) cout << "first" << endl;
        else cout << "second" << endl;
    }
    else
    {
        int x = comp(ff, ss);
        //cout << x << endl;
        if(x == 0)
        {
            if(last == 1) cout << "first" << endl;
            else cout << "second" << endl;
        }
        else if(x == 1) cout << "first" << endl;
        else cout << "second" << endl;

    }
//    else if(ff == ss)
//    {
//        if(last == 1) cout << "first" << endl;
//        else cout << "second" << endl;
//    }
//    else
//    {
//        if(ff.compare(ss) > 0) cout << "first" << endl;
//        else cout << "second" << endl;
//    }
}


int main()
{
    solve();
}
