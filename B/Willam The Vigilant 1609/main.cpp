#include<bits/stdc++.h>
using namespace std;


void solve()
{
    int n, q;
    cin >> n >> q;
    vector<char> myvec(n);

    for(int i = 0; i < n; i++)
    {
        cin >> myvec[i];

    }
    int count = 0, j = 0;
    for(int i = 0; i + 2 < n;)
    {
        if(myvec[i] == 'a' && myvec[i + 1] == 'b' && myvec[i + 2] == 'c')
        {
            count++;


            i += 3;
        }

        else {i++;}

    }
    //for (auto elem : prefix) cout << elem << " ";

    for(int i = 0; i < q; i++)
    {
        int x; char c;
        cin >> x >> c;
        x--;
        if(myvec[x] == c)
        {
            cout << count << endl;

        }
        else
        {
            if(myvec[x] == 'a')
            {
                if(x + 2 < n && myvec[x+1] == 'b' && myvec[x+2] == 'c' )
                {
                    //cout << "inside a and count--";
                    count--;
                }

                if(c== 'b' && myvec[x-1] =='a' && myvec[x+1] == 'c' && x -1 >=0 && x+1<n)
                {
                    //cout << "inside a and abc";
                    count++;
                }
                if(c== 'c' && myvec[x-2] =='a' && myvec[x-1] == 'b' && x -2 >=0 )
                {
                    count++;
                }
                myvec[x] = c;

            }
            else if(myvec[x] == 'b')
            {
                if(x-1 >= 0 && x + 1 < n && myvec[x-1] == 'a' && myvec[x+1] == 'c' )
                {
                    //cout << "inside b and count--";
                    count--;
                }
                if(c== 'a' && myvec[x+1] =='b' && myvec[x+2] == 'c' && x+2<n)
                {
                    //cout << "inside b and abc";
                    count++;
                }
                if(c== 'c' && myvec[x-2] =='a' && myvec[x-1] == 'b' && x -2 >=0 )
                {
                    count++;
                }
                myvec[x] = c;
            }

            else if(myvec[x] == 'c')
            {
                if(x - 2 >= 0  && myvec[x-1] == 'b' && myvec[x-2] == 'a' )
                {
                    //cout << "inside c and count--";
                    count--;
                }
                if(c== 'a' && myvec[x+1] =='b' && myvec[x+2] == 'c' && x+2<n)
                {
                    //cout << "inside c and abc";
                    count++;
                }
                if(c== 'b' && myvec[x-1] =='a' && myvec[x+1] == 'c' && x - 1 >= 0 && x + 1 < n )
                {
                    count++;
                }
                myvec[x] = c;
            }
            //for (auto elem : myvec) cout << elem << " "  ;
            cout << count;
            cout  << endl;
        }
    }
}

int main()
{
    int t = 1;
    //cin >> t;
    while(t--) solve();
}
