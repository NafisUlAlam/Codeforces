#include <bits/stdc++.h>

using namespace std;

int main(){
    unordered_map<string,int> unmap;
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        if(unmap.find(s) == unmap.end()){
            unmap[s]++;
            cout << "OK" << endl;
        }
        else{
            int num = unmap[s];
            unmap[s]++;
            string s2 = to_string(num);
            s += s2;
            cout << s << endl;
        }
    }
}
