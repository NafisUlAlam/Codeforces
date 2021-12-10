#include <bits/stdc++.h>

#define ll long long
using namespace std;



int main()
{
    int m, s;
    cin >> m >> s;
    if(s <= 0)
    {
        if(m > 1)
        {
            cout << -1 << " " << -1;
            return 0;
        }
        else {cout << 0 << " " << 0; return 0;}

    }
    if(s > (9 * m))
    {
        cout << -1 << " " << -1;
        return 0;
    }

    vector<int> v(m,0);

    int i = 0;
    while(s > 0)
    {
        if(s > 9)
        {
            v[i] = 9;
            s -= 9;
        }
        else
        {
            v[i] = s;
            s = 0;
        }
        i += 1;
    }


    string mymax;
    for (auto elem : v)
    {
        mymax += (to_string(elem));
    }

    string mymin;

    reverse(v.begin(),v.end());

    if(v[0] == 0)
    {
        v[0] = 1;
        for(int i = 1; i < v.size(); i++)
        {
            if(v[i] == 0) continue;
            else
            {
                v[i] = v[i] - 1; break;
            }
        }
    }

    for (auto elem : v)
    {
        mymin += (to_string(elem));
    }
    cout << mymin << " "<< mymax;
}
