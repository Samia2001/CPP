#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
     ll n, m, a, b, x = 0, i, p, q;

    cin>>n>>m;
    set<pair<ll,ll> >s1,s2,s;

    for(i = 0 ; i < m ; i++)
    {
        cin >> a >> b;

        if(a > b)
            swap(a, b);

        s1.insert({a, b});
        s.insert({a, b});
    }

    cin >> p >> q;

    for(i = 0 ; i < q ; i++)
    {
        cin >> a >> b;

        if(a > b)
            swap(a, b);

        s2.insert({a, b});
        s.insert({a, b});
    }

    if(n != p || ((s1.size() + s2.size())!= s.size()))
        cout << "NO";
    else
    {
        cout << "YES";
    }
    cout << endl;
}
