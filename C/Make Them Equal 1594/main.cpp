#include<bits/stdc++.h>

using namespace std;
const int sz = 3e5 + 1;
vector<int> primes;
vector<bool> primes1(sz,true);

void sieve()
{
    primes1[0] = primes1[1] = false;
    for(int i = 2; i * i < sz; i++)
    {
        if(primes1[i] == true)
        {
            for(int j = i * i; j < sz; j += i)
            {
                primes1[j] = false;
            }
        }

    }
    for(int i = 2; i < sz; i++)
    {
        if(primes1[i] == true) primes.push_back(i);
    }
    /*for(auto elem : primes) cout << elem << " " ;
    cout << endl;*/
}


bool checkodd(set<int>& s)
{
    for(auto elem : s)
    {
        if(elem % 2 == 0) return false;
    }
    return true;
}
bool checkeven(set<int>& s)
{
    for(auto elem : s)
    {
        if(elem % 2 == 1) return false;
    }
    return true;
}

void solve()
{
    int n;
    char c;
    cin >> n >> c;
    vector<char> myvec(n+1);
    unordered_set<int> myset;
    for(int i = 1; i <= n; i++)
    {
        cin >> myvec[i];
        if(myvec[i] != c) myset.insert(i);
    }
    //for (auto elem : myset) cout << elem << " ";
    //cout << endl;
    if(myset.size() == 0) cout << 0 << endl;

    else
    {


            int mydivisor = -1;
            for(int i = 2; i <= n; i++)
            {
                if(myset.count(i) > 0) continue;
                bool divisorfound = false;
                for(auto setelem : myset)
                {
                    if(setelem % i == 0)
                    {

                        divisorfound = true;
                        break;
                    }
                }
                if(divisorfound == false)
                {
                    mydivisor = i; break;
                }
            }

            if (mydivisor != -1)
            {
                cout << 1 << endl;
                cout << mydivisor << endl;
            }

            else
            {
                cout << 2 << endl;
                cout << n-1<< " " << n << endl;
            }




    }
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--) solve();
}
