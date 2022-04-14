#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

void printPair(ull& n)
{
    for (int i = 0; i < n / 2; i++)
    {
        cout << i << " " << n - i - 1 << endl;
    }
}

vector<ull> myvec;
void printPair(ull n, ull pair1, ull pair2)
{
    myvec.clear();
    for (int i = 0; i < n / 2; i++)
    {
        if(n - i - 1 == pair2 || i == pair1 || i == pair2 || n - i - 1 == pair1)
        {
            //cout << "pushed back "<< i << " " << n - i - 1 << endl;
            myvec.push_back(i);
            myvec.push_back(n - i - 1);
            continue;
        }
        cout << i << " " << n - i - 1 << endl;
    }
    cout << pair1 << " " << pair2 << endl;
    for(int i = 0; i < 4; i++)
    {
        if(myvec[i] != pair1 && myvec[i] != pair2) cout << myvec[i] << " ";

    }
    cout << endl;
}

void printPair(ull n, ull pair1, ull pair2, ull pair3, ull pair4)
{
    myvec.clear();
    for (int i = 0; i < n / 2; i++)
    {
        if(n - i - 1 == pair2 || i == pair1 || i == pair2 || n - i - 1 == pair1 ||
            n - i - 1 == pair3 || i == pair3 || i == pair4 || n - i - 1 == pair4 )
        {
            //cout << "pushed back "<< i << " " << n - i - 1 << endl;
            myvec.push_back(i);
            myvec.push_back(n - i - 1);
            continue;
        }
        cout << i << " " << n - i - 1 << endl;
    }
    cout << pair1 << " " << pair2 << endl;
    cout << pair3 << " " << pair4 << endl;
    for(int i = 0; i < 6; i++)
    {
        if(myvec[i] != pair1 && myvec[i] != pair2 &&
            myvec[i] != pair3 && myvec[i] != pair4) cout << myvec[i] << " ";

    }
    cout << endl;
}

void solve()
{
    ull n, k;
    cin >> n >> k;
    if(k == 0) printPair(n);
    if(k > 0 && k < n - 1)
    {
        printPair(n , k, n - 1);
    }
    if(k == n-1)
    {
        if (n > 4)printPair(n, n - 1, n - 2, n - 3, 1 );
        else cout << -1 << endl;
    }

}
int main()
{
    int t;
    cin >> t;
    while(t--) solve();
}
