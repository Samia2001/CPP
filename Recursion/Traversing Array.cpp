/*input-
    5
    1 2 3 4 5
  output-
    1 2 3 4 5//forward
    5 4 3 2 1//backward
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
void fun(ll a[] , ll n , ll i)
{
    if (i == n)return;
    else
    {   
        cout << a[i] << " ";//forward print
        fun(a, n, i + 1);
        cout << a[i] << " ";//backward pring 

    }
}
int main()  {

#ifndef ONLINE_JUDGEs
    freopen("input.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);
#endif
    ll n , i;
    cin >> n;
    ll a[n + 1];
    for (i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }

    fun(a, n, 0);
}

