#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& a)
{
    int i = 0, n = a.size(), cnt = 0;
    string s;
    while(i < n)
    {
        cout << a[i] << endl;
        cin >> s;
        if(s == "yes")
        {
            cnt++;
            if(a[i] * a[i] <= 100)
            {
                cout << a[i] * a[i] << endl;
                cin >> s;
                if(s == "yes") cnt++;
            }
        }
        if(cnt > 1) break;
        i++;
    }
    if(cnt <= 1) cout << "prime" << endl;
    else cout << "composite" << endl;
}

int main()
{
    vector<int> a = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    solve(a);
}
