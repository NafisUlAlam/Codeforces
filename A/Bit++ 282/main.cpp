#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int val = 0;
    while(t--){

        string s;
        cin >> s;
        if ((s[0] == '+' && s[1] == '+' ) || (s[1] == '+' && s[2] == '+' )){
            val += 1;
        }
        if ((s[0] == '-' && s[1] == '-' ) || (s[1] == '-' && s[2] == '-' )){
            val -= 1;
        }

    }
     cout << val << endl;
}
