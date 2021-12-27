// Number of Equal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    

        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        vector<int> b(m);
        for (size_t i = 0; i < n; i++)
        {
            cin >> a[i];

        }
        for (size_t i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        int i = 0;
        vector<int> result(m);
        for (int j = 0; j < m; j++)
        {
            unsigned long long counter = 0;
            if (j >= 1 && b[j] == b[j - 1])
            {
                result[j] = result[j - 1];
                continue;
            }
            while (i < n && a[i] < b[j]) i += 1;
            while (i < n && a[i] == b[j])
            {
                counter += 1; 
                i += 1;
            }
            result[j] = counter;      
        }
        unsigned long long sum = 0;
        for (auto elem : result) sum += elem;
        cout << sum;
    
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
