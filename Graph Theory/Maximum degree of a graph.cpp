#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>v[1000];
bool vis[1000];
vector<ll>ans;

int main()
{
    ll n, m, i, a, b , mx = 0;
    cin >> n >> m;

    for(i = 0 ; i < m ; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        mx = max(mx , max((ll)v[a].size(),(ll)v[b].size()));
    }
    cout << mx;

    return 0;
}
