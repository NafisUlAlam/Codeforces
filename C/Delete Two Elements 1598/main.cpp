#include <bits/stdc++.h>

using namespace std;

void solve2()
{
    int n;
    cin >> n;
    vector<int> myvec(n);
    map<int,int> mymap;
    double mean = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> myvec[i];
        mean += myvec[i];
        mymap[myvec[i]]++;
    }
        mean /= n;
        sort(myvec.begin(),myvec.end());
        int i = 0, j = myvec.size() - 1;

        long long result = 0;
        while(j - i > 0)
        {

            if(myvec[i] + myvec[j] > (2 * mean)) j--;
            else if(myvec[i] + myvec[j] < (2 * mean)) i++;
            else
            {
                if(myvec[i] != myvec[j])
                {
                    long long count1 = mymap[myvec[i]];
                    long long count2 = mymap[myvec[j]];
                    result += count1 *1ll * count2;

                    i = i + mymap[myvec[i]];
                    j = j - mymap[myvec[j]];
                }
                else
                {
                    result += ((j - i + 1) * 1ll * (j - i)) / 2;

                    break;
                }
            }

        }
        cout << result << endl;



}
void solve()
{
    int n;
    cin >> n;
    vector<double> myvec(n);
    map<double,double> mymap;
    long double mean = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> myvec[i];
        mean += myvec[i];
        mymap[myvec[i]]++;
    }
    mean /= (n * 1.0);

    long long result = 0;
    for(int i = 0; i < n; i++)
    {
        double current = myvec[i];
        double needed = (2.0 * mean) - current;


        if(current == needed)
        {
            result += (mymap[current] * 1ll * (mymap[current] - 1)) / 2;
        }
        else
        {
            result += mymap[current] * 1ll * mymap[needed];
        }
        mymap[current] = 0; mymap[needed] = 0;
    }
    cout << result << endl;



}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
