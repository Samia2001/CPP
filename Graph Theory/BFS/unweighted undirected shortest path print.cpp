#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll vis[1000], dis[1000], level[1000];
std::vector<ll> v[1000], ans;
map<ll,ll>mp;
ll x;
void bfs(ll s , ll n)
{
   queue<ll>q;
   q.push(s);
   vis[s] = 1;
   level[s] = 0;
   

   while (q.size())
   {
      ll u = q.front();
      if (u == n)
         return;

      q.pop();
      for (auto it : v[u])
      {
         if (vis[it] == 0)
         {
            vis[it] = 1;
            dis[it] = dis[u] + 1;
            q.push(it);
         }

      }

   }
}
void afs(ll s)
{
   queue<ll>q;
   q.push(s);
   vis[s] = 1;
   ans.push_back(s);

   while (q.size())
   {
      ll u = q.front();
      if (u == 1)
         return;

      q.pop();
      for (auto it : v[u])
      {
         if (vis[it] == 0)
         {
            vis[it] = 1;
            if(dis[u]-1==dis[it])
            {
               ans.push_back(it);
               q.push(it);
               break;
            }
            
         }

      }

   }
}
int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("outp1.txt", "w", stdout);
#endif
   ll n , m, a, b, i;
   cin >> n >> m;
   for (i = 0 ; i < m ; i++)
   {
      cin >> a >> b;
      v[a].push_back(b);
      v[b].push_back(a);
   }
   bfs(1, n);
   memset(vis, 0, sizeof(vis));

   cout<<dis[n]<<endl;
   afs(n);
   for(i = 0 ; i<ans.size();i++)cout<<ans[i]<<" ";
   
}
