#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>v[1006];
bool vis[1006];
vector<ll>ans;

void dfs(int s)
{
    vis[s] = 1;
    ans.push_back(s);
    vector<ll>::iterator it;
    for(it = v[s].begin() ; it!= v[s].end() ; it++)
    {
        if(vis[*it]==0)
        {
            vis[*it] = 1;
            dfs(*it);
        }
    }

}

int main()
{
    ll n, m, i, a, b, mn = 1e18 , x = 0;
    cin >> n >> m;

    for(i = 0 ; i<m ; i++)
    {
        cin >> a >> b;
        if(a != b)
        {
            v[a].push_back(b);
            v[b].push_back(a);
        }
    }

    for(i = 1 ; i<=n ; i++)
    {
        if(ll(v[i].size())<=mn)
        {
            mn = min(ll(v[i].size()),mn);
            x = i;
        }
    }

    cout << mn << endl;

    for(i = 0 ; i<v[x].size() ; i++)
    {
        cout<<x<<" "<<v[x][i]<<" "<<endl;
    }


    return 0;
}
