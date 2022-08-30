/*input-
6 5
1 2
1 3
2 4
2 5
5 6
output-3
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll vis[1000],dis[1000];
std::vector<ll> v[1000];
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
            dis[it]=dis[u]+1;
            vis[it] = 1;
            q.push(it);

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
   cout<<dis[6];
}
