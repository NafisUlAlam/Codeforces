#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    int counter = 0;
    bool flag = true;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.size(); i++){

        if(!st.empty()){
            if(st.top() == s[i]) counter += 1;
            else counter = 0;
        }
        if (counter == 6){
            cout << "YES";
            flag = false;
            break;
        }
        st.push(s[i]);
    }
    if(flag) cout << "NO";
}
