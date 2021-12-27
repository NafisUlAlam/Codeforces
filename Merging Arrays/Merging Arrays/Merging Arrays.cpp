// Merging Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    vector <int> c(n + m );

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    

    
    int i = 0, j = 0 , k = 0;
    while (i < a.size() || j < b.size())
    {
        if (j >= b.size() || (i < a.size() && a[i] < b[j]))
        {
            c[k++] = a[i++];
        }
        else c[k++] = b[j++];
    }

    for (auto elem : c) cout << elem << " ";


}

