#include<bits/stdc++.h>
using namespace std;

bool isPunctuation(char c)
{
    return c == ',' || c == '.' || c == '?' || c == '!';
}
void solve()
{
   string s, t;
   getline(cin, s);
   int n =(int) s.size();
   for(int i = 0; i < n; i++)
   {
       if(s[i] >= 'a' && s[i] <= 'z')
       {
           t.push_back(s[i]);
       }
       else if(s[i] == ' ')
       {
           int j = i;
           while(j < n && s[j] == ' ') j++;
           if(( j < n && !isPunctuation(s[j]) ) ) t.push_back(' ');
           i = j - 1;
       }
       else if(isPunctuation(s[i]))
       {
           t.push_back(s[i]);
           int j = i + 1;
           while(j < n && s[j] == ' ') j++;
           if(j < n) t.push_back(' ');
           i = j - 1;
       }
   }
   cout << t << endl;
}

int main()
{
    solve();
}
