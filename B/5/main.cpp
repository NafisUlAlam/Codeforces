#include <bits/stdc++.h>

using namespace std;

void align(string& e, int& maxi, bool& flag)
{
    int spaces = maxi - 2 - (int)e.size();
    int left = spaces / 2;
    int right = spaces - left;
    if(left != right)
    {
        if(flag == true)swap(left, right);
        flag = !flag;
    }
    string a(left, ' '), b(right, ' ');
    cout << "*" << a << e << b << "*" << endl;
}

void solve()
{
    string s;
    vector<string> strings;
    int maxi = 0;
    while(getline(cin, s))
    {
        //cout <<"getting " << endl;
        strings.push_back(s);
        maxi = max(maxi, (int)s.size());
        //for(auto e : strings) cout << e << " ";
    }
    maxi += 2;
    for(int i = 1; i <= maxi; i++) cout << "*"; cout << endl;
    bool flag = false;
    for(auto e : strings) align(e, maxi, flag);
    for(int i = 1; i <= maxi; i++) cout << "*"; cout << endl;
}

int main()
{
    solve();
}
