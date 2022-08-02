/*input-
   5 
   1 2 3 4 5
  output-
   15
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll fun(ll a[] , ll n , ll i , ll s)
{
    if (i == n)return s;
    else
    {   
        return fun(a, n, i+1 , s+a[i]);
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

    cout<<fun(a, n, 0 , 0);
}

