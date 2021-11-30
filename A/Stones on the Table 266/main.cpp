#include <bits/stdc++.h>

using namespace std;

int main(){
//    int n;
//    int countR, countG, countB;
//    countR = countG = countB = 0;
//    cin >> n;
//    char arr[n+1];
//    arr[0] ='a';
//    for (int i = 1; i < n + 1; i++){
//
//        cin >> arr[i];
//        if(arr[i] == arr[i-1]){
//            if (arr[i] == 'R'){
//                countR += 1;
//            }
//            else if( arr[i] == 'G'){
//                countG += 1;
//            }
//            else {
//                countB += 1;
//            }
//        }
//    }
//
//    cout << countB + countG + countR;
    int n;
    cin >> n;
    stack<char> st;
    int counter = 0;
    for (int i = 1; i <= n; i++){
        char c;
        cin >> c;
        if(st.empty()){
            st.push(c);
        }
        else{
            char stackTop = st.top();
            if (stackTop == c) counter += 1;
            else st.push(c);
        }
    }
    cout << counter;

}
