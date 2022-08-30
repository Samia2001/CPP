#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool vis[1000];
std::vector<ll> v[1000];
void bfs(ll s)
{
   queue<ll>q;
   q.push(s);

   vis[s] = 1;

   while (q.size())
   {
      ll u = q.front();
      cout << u << endl;
      q.pop();
      for (auto it : v[u])
      {
         if (vis[it] == 0)
         {
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
}
