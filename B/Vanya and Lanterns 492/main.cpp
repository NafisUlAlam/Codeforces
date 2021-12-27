#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;


ull n,l;
double eps = 1e-10;
vector<ull> lightposition;

pair<double,double> street;


void reset()
{
    street = {100,0};
}

void mark(double st, double fin)
{
    //cout <<" st "<< st << " fin " << fin << endl;
    if (st <= 0) st = 0;
    if (fin > l) fin = l;
    street.first = min(street.first,st);
    if(street.first == 0 && st <= street.second) street.second = max(street.second,fin);

    //cout <<" first "<< street.first << " second " << street.second << endl;
}

bool check(double x)
{
    reset();
    //cout <<"for "<<   x << endl;
    for(int i = 0; i < n; i++)
    {
        double currlight = lightposition[i];
        mark(currlight - x,currlight + x);

    }

    //cout << street.first << " " << street.second << endl;



    return (street.first <= 0 && street.second >= l);

}


int main()
{
    cin >> n >> l;
    lightposition.assign(n,0);
    reset();


    for (int i = 0; i < n; i++)
    {
        cin >> lightposition[i];
    }

    sort(lightposition.begin(), lightposition.end());

    //for (auto elem : lightposition) cout << elem << " ";
    //cout << endl;
    double left = 0; double right = l;
    //cout << check(1.875);
    while(right - left > eps)
    {
        double mid = (left + right) / 2.0;
        if(check(mid)) right = mid;
        else left = mid;
    }
    double ans;
    if(check(left)) ans = left;
    else ans = right;


    cout << fixed << setprecision(9) << ans << endl;

}
