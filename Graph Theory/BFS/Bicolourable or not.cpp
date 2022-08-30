/*input-3 3
1 2
1 3
2 3
output-
NOT bicolourable
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll vis[1000],dis[1000];
std::vector<ll> v[1000];
ll x;
void bfs(ll s)
{
   queue<ll>q;
   q.push(s);
   dis[s] = 0;
   vis[s] = 1;

   while (q.size())
   {
      ll u = q.front();
      q.pop();
      for (auto it : v[u])
      {
         if (vis[it] == 0)
         {
            dis[it]=1-dis[u];
            vis[it] = 1;
            q.push(it);

         }
         else
         {
            if(dis[it]==dis[u])
               x = 1;
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
   if(x)cout<<"NOT bicolourable";
   else cout<<"bicolourable";
}
