#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ull a, s, b;
        string a1, s1;
        bool flag = true;

        cin >> a >> s;
        a1 = to_string(a);
        s1 = to_string(s);

        stack<int>b1;

        int i = a1.size() - 1;
        int j = s1.size() - 1;

        while(i >= 0 && j >= 0)
        {
            int x = a1[i] - '0';
            int y = s1[j] - '0';

            if(y >= x) b1.push(y - x);

            else
            {
                if(j >= 1)
                {
                    y = (10 * (s1[j-1] - '0')) + (s1[j] - '0');
                    if(y >= 10 && y <= 18)
                    {
                        j -= 1;
                        b1.push(y - x);
                    }
                    else
                    {
                        flag = false;
                        break;

                    }

                }
                else
                {
                    flag = false;
                    break;
                }
            }
            i -= 1; j -= 1;
        }


        if(i < 0 && j >= 0)
        {
            while(j >= 0)
            {
                b1.push(s1[j]-'0');
                j -= 1;
            }
        }
        else if(i >= 0 && j < 0)
        {
           flag = false;
        }
        if (flag == false) cout << - 1 << endl;
        else
        {
            while(b1.top() == 0)
            {
                b1.pop();
            }
            while(!b1.empty())
            {
                cout << b1.top(); b1.pop();
            }
            cout << endl;
        }



    }
}
