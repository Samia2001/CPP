#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;

    set<pair<int, int> > s;

    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b ;

        if(a == b)
            continue;
        if(b>a)
            swap(a, b) ;

        s.insert({a, b}) ;
    }

    if(s.size() == m && n*(n-1)/2 == m)
        cout << "YES" << endl ;
    else
        cout << "NO" << endl ;

    return 0;
}
