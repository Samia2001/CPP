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
    ll n, m, i, a, b , c = 0;
    cin >> n >> m;

    for(i = 0 ; i<m ; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(i = 1 ; i <= n ; i++)
    {
        if(v[i].size()%2)
            c++;
    }
    if(c>2)
        cout<<"Neither euler path nor euler circuit"<<endl;
    else
    {
        if(c == 2)//c == 1 means degree will be 1.which is not possible
        {
            cout<<"Only euler path not euler circuit";
        }
        else
        cout<<"Euler path and euler circuit";
    }


    return 0;
}
