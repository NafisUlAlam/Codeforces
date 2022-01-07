#include <bits/stdc++.h>

using namespace std;


bool checkPalindrome(const vector<int>& myvec)
{
    int i = 0, j = myvec.size()  - 1;
    while(j - i >= 1)
    {
        if(myvec[i] != myvec[j]) return false;
        i++; j--;
    }
    return true;
}

bool checkPalindrome(const vector<int>& myvec, int elem)
{
    int i = 0, j = myvec.size()  - 1;
    while(j - i >= 1)
    {
        if(myvec[i] == elem)
        {
            while (myvec[i] == elem) i++;
        }
        if(myvec[j] == elem)
        {
            while (myvec[j] == elem) j--;
        }
        if(myvec[i] != myvec[j]) return false;
        i++; j--;
    }
    return true;
}

void solve2()
{
    int n;
    cin >> n;
    vector<int> myvec(n);
    set<int> myset;
    for(int i = 0; i < n; i++)
    {
        cin >> myvec[i];
        myset.insert(myvec[i]);
    }
    bool ispalin = false;
    ispalin = checkPalindrome(myvec);


    bool other = false;



    for(auto elem : myset)
    {
        other = other || checkPalindrome(myvec, elem);
    }
    if(ispalin || other) cout << "YES" << endl;
    else cout << "NO" << endl;
}


bool first(vector<int>& myvec)
{
    int i = 0, j = myvec.size() - 1;

    int start = -1;

    bool firstcase = true;
    bool secondcase = true;

    while(i <= j)
    {

        if(myvec[i] == start)
        {
            while(myvec[i] == start) i++;
        }
        if(myvec[j] == start)
        {
            while (myvec[j] == start) j--;
        }


        if(myvec[i] == myvec[j]){i++; j--;}
        else
        {
            if (firstcase == true)
            {
                start = myvec[i];
                while(myvec[i] == start)
                {
                    i++;
                }
                firstcase = false;
            }
            else
            {
                secondcase = false;
                break;
            }
        }
    }
    return secondcase;

}
bool second(vector<int>& myvec)
{
    int i = 0, j = myvec.size() - 1;

    int start = -1;

    bool firstcase = true;
    bool secondcase = true;

    while(i <= j)
    {

        if(myvec[i] == start)
        {
            while(myvec[i] == start) i++;
        }
        if(myvec[j] == start)
        {
            while (myvec[j] == start) j--;
        }

        if(myvec[i] == myvec[j]){i++; j--;}
        else
        {
            if (firstcase == true)
            {
                start = myvec[j];
                while(myvec[j] == start)
                {
                    j--;
                }
                firstcase = false;
            }
            else
            {
                secondcase = false;
                break;
            }
        }
    }
    return secondcase;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> myvec(n);
    set<int> myset;
    for(int i = 0; i < n; i++)
    {
        cin >> myvec[i];

    }
    bool ispalin = false;
    ispalin = checkPalindrome(myvec);



    bool firstcase = first(myvec);
    bool secondcase = second(myvec);


   if(firstcase || ispalin || secondcase) cout << "YES" << endl;
   else cout << "NO" << endl;


}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
}
