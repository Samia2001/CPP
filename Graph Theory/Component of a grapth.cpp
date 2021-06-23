#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>v[1006];
bool vis[1006];

void dfs(int s)
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
    ll n, m, i, a, b , cnt = 0;
    cin >> n >> m;

    for(i = 0 ; i < m ; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(i = 1 ; i <= n ; i++)
    {
        if(vis[i]==0)
        {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt <<endl;
    return 0;
}
