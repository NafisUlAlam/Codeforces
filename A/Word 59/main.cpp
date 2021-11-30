#include <iostream>

using namespace std;

int main()
{
    string s, output1,output2;
    cin >> s;
    int uppercount, lowercount;
    uppercount = lowercount = 0;
    for (int i = 0; i < s.size(); i++){
        output1 += toupper(s[i]);
        output2 += tolower(s[i]);
        if(isupper(s[i])) uppercount += 1;
        else lowercount += 1;
    }
    if (lowercount >= uppercount){
        cout << output2;
    }
    else{
        cout << output1;
    }

}
