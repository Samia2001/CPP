#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll>v[1006];
bool vis[1006], col[1006];

bool dfs(int s, int c)
{
    vis[s] = 1;
    col[s] = c;
    vector<ll>::iterator it;
    for(it = v[s].begin() ; it!= v[s].end() ; it++)
    {
        if(vis[*it]==0)
        {
            if(dfs(*it, c^1)==false)
                return false;
        }
        if(col[s] == col[*it])
            return false;
    }
    return true;

}
int main()
{

    ll n, m, i, a, b, x = 0;
    cin >> n >> m;

    for(i = 0 ; i< m ; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(i = 1 ; i <= n ; i++)
    {
        if(vis[i]==0)
        {
            if(dfs(i, 0)==false)
            {
                x = 1;
                break;
            }
        }
    }
    if(x == 1 || n == 1)
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        for(i = 1 ; i <= n ; i++)
        {
            if(col[i])
                cout<<i<<" ";
        }
        cout<<endl;
        for(i = 1 ; i <= n ; i++)
        {
            if(col[i]==0)
                cout<<i<<" ";
        }
    }

    return 0;
}
