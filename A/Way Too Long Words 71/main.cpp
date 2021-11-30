#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int len = s.size();
        if (len > 10){
            string output;
            output += s[0];
            int diff = len - 2;
            output += to_string(diff);
            output += s[len - 1];
            cout << output << endl;
        }
        else{
            cout << s << endl;
        }
    }
}
