#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    unordered_set<char> charset;
    for (int i = 0; i < s.size(); i++){
        charset.insert(s[i]);
    }
    if (charset.size() & 1) cout << "IGNORE HIM!";
    else cout << "CHAT WITH HER!";
}
