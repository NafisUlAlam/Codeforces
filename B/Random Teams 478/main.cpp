#include <bits/stdc++.h>

using namespace std;


long long findMin(long long n, long long m){
    if (m > 1){

        long long a = n / m;
        long long mod = n % m;
        long long c = (mod * (((a + 1)) * a) )/ 2;
        long long d = (m - mod) * ((a) * (a - 1)) / 2;
        return c + d;
    }
    else {
        long long c = (n * (n-1));
        return c / 2;
    }
}
long long findMax(long long n, long long m){
    if(m > 1){

        long long maxteam = n - (m-1);
        return ((maxteam) * (maxteam - 1) / 2);
    }
    else {
        long long c = (n * (n-1));
        return c / 2;
    }
}
int main()
{
    long long n,m;
    cin >> n >> m;
    cout << findMin(n,m) << " " << findMax(n,m);

}
