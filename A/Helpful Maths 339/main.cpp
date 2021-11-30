#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    if(s.size() <= 2) cout << s;
    else{
        string output;
        sort(s.begin(),s.end());
        for (int i = 0; i < s.size(); i++){
            if(s[i] == '+') continue;
            else{
                if(i < s.size()-1){
                    output += s[i];
                    output += '+';
                }
                else output += s[i];
            }
        }
        cout << output;
    }
}
