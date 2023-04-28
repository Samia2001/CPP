#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define    rep(X,Y)     for(X=0;X<Y;X++)
#define    rrep(X,Y)     for(X=Y-1;X>=0;X--)
#define    rep1(X,Y)    for(X=1;X<=Y;X++)
#define ml ll T,g; cin>>T; for(g=0;g<T;g++)
#define nml ll T = 1,g; for(g=0;g<T;g++)
#define case "Case "<<g+1<<": "
#define pb push_back
#define pll pair<ll , ll>
using namespace std;
vector<ll> v[100005];

ll vis[100005], dp[100005] ;

ll dfs(ll s) {
  vis[s] = 1 ;
  
  if(dp[s]) return dp[s] ;
  //cout << s << endl ;
  ll mx=0 ;
  for(auto it: v[s]) {
    if(!vis[it]) {
      mx = max(mx, dfs(it)) ;
    } else {
      mx = max(mx, dp[it]) ;
    }
  }
  
  return dp[s] = max(mx+1, dp[s]) ;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("out1.txt", "w", stdout);
#endif
  ll i,j;
  ll n , m, a, b, mx = 0;
  cin >> n >> m;
  rep(i , m)
  {
    cin >> a >> b;
    v[a].push_back(b);
  }
  rep1(i , n)
  {
    //cout<<dfs(i)<<endl;
    if(vis[i]==0)
    mx = max(mx, dfs(i)-1);
  }
  cout << mx << endl;
  return 0;
}
