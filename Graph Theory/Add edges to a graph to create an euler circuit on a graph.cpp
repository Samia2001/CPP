#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>v[100006];
bool vis[100006];

void dfs(ll s)
{
    vis[s] = 1;
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
    ll n, m, i, a, b, c = 0;
    cin >> n >> m;
    vector<ll>v1;

    for(i = 0 ; i<m ; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(i = 1 ; i <= n ; i++)
    {
        if(v[i].size()%2)
        {
            c++;
            v1.push_back(i);
        }
    }

    cout<<c/2<<endl;

    for(i = 0 ; i < v1.size(); i = i+2)
    {
        cout<<v1[i]<<" "<<v1[i+1]<<endl;
    }

    return 0;
}
