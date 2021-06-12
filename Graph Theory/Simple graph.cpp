#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n , m , a , b , x = 0 , i;

    cin >> n >> m;

    set<pair<ll , ll > >s;

    for(i = 0 ; i < m ; i++)
    {
       cin >> a >> b;

       if(a==b)
           x = 1;

       else if(a>b)
            swap(a , b);

        s.insert({a , b});
    }

    if(s.size() == m && x == 0)
        cout << "YES";
    else
        cout << "NO";

    cout << endl;
}
