/*input-
4 4
1 2
2 4
1 3
3 4
output-
2
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll vis[1000], dis[1000],path[1000];
std::vector<ll> v[1000];
ll x;
void bfs(ll s)
{
   queue<ll>q;
   q.push(s);
   for(ll i = 0 ; i<1000;i++)dis[i]=1e18;
   dis[s] = 0;
   path[s] = 1;
   vis[s] = 1;

   while (q.size())
   {
      ll u = q.front();
      q.pop();
      for (auto it : v[u])
      {
          if (dis[it] > dis[u]+1)
            {  dis[it] = dis[u] + 1;
               path[it] = path[u];
               q.push(it);
            }
           
         else if (dis[it] == dis[u]+1)
         {
               path[it]+=path[u];
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
   bfs(1);
   cout<<path[4];
   
}
