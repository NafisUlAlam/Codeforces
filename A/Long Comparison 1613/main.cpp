#include <bits/stdc++.h>

#define ull unsigned long long

using namespace std;

int main()
{

    ull t;
    cin >> t;
    while (t--){
        bool flag = false;
        ull x1,p1,x2,p2;
        cin >> x1 >> p1;
        cin >> x2 >> p2;
        ull digits1 = log10(x1) + 1 + p1;
        ull digits2 = log10(x2) + 1 + p2;
        string s1 = to_string(x1);
        string s2 = to_string(x2);
        bool foundans = false;
        if (digits1 > digits2) cout << '>' << endl;

        else if (digits1 < digits2) cout << '<' << endl;

        else if (digits1 == digits2){

            if(s1.size() == s2.size()){
                if(x1 == x2) cout << '=' << endl;
                else if(x1 > x2) cout << '>' << endl;
                else cout << '<' << endl;
            }
            else if (s1.size() > s2.size()){
                for (int i = 0; i < s2.size(); i++){
                    if((s1[i] -'0') > (s2[i] -'0')) {cout << '>' << endl; foundans = true; break;}
                    else if((s1[i] -'0') < (s2[i] -'0')){cout << '<' << endl; foundans = true; break;}
                    else continue;
                }
                if(!foundans){

                    for (int i = s2.size(); i < s1.size(); i++){
                        if((s1[i] -'0') > 0) {cout << '>' << endl; foundans = true; break;}
                        else continue;
                    }
                }
                if (!foundans) cout << '=' << endl;
            }
            else{
                 for (int i = 0; i < s1.size(); i++){
                    if((s1[i] -'0') > (s2[i] -'0')) {cout << '>' << endl; foundans = true; break;}
                    else if((s1[i] -'0') < (s2[i] -'0')){cout << '<' << endl; foundans = true; break;}
                    else continue;
                }
                if(!foundans){

                    for (int i = s1.size(); i < s2.size(); i++){
                        if((s2[i] -'0') > 0) {cout << '<' << endl; foundans = true; break;}
                        else continue;
                    }
                }
                if (!foundans) cout << '=' << endl;

            }
        }



//        string s1 = to_string(x1);
//        string s2 = to_string(x2);
//        char zero = '0';
//        for (int i = 0; i < p1; i++){
//            s1 += zero;
//        }
//        for (int i = 0; i < p2; i++){
//            s2 += zero;
//        }
//        if(s1.size() > s2.size()) cout << '>' << endl;
//        else if (s1.size() < s2.size()) cout << '<' << endl;
//        else{
//            for (int i = 0; i < s1.size(); i++){
//                if((s1[i] - '0') > (s2[i] - '0')) {cout << '>' << endl;flag = true; break;}
//                else if ((s1[i] - '0') < (s2[i] - '0')) {cout << '<' << endl;flag = true ; break;}
//            }
//            if(!flag)cout << '=' << endl;
//        }
    }


}
