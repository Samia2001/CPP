#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define    rep(X,Y)     for(X=0;X<Y;X++)
#define    rrep(X,Y)     for(X=Y-1;X>=0;X--)
#define    rep1(X,Y)    for(X=1;X<=Y;X++)
#define ml ll T,g; cin>>T; for(g=0;g<T;g++)
#define nml ll T = 1,g; for(g=0;g<T;g++)
#define case "Case "<<g+1<<":"
#define pb push_back
#define pll pair<ll , ll>
using namespace std;
ll dp[505][505];
ll rect(ll a , ll b)
{
  ll i;
  if(a>b)swap(a,b);
  if (a == b)return 0;
  if(a==1 )
  {
      return b-1;
   
  }
  ll mn=1e18, p=1e18, q=1e18;
  if(dp[a][b]!=-1)return dp[a][b];
  for (i = 1; i < a; i++)
  {
    p = 1 + rect(a - i, b) + rect(i, b);
    mn = min(mn,p);
  }
  for (i = 1; i < b; i++)
  {
    q = 1 + rect(a, b - i) + rect(a, i);
    mn = min(mn,q);
    
  }
  return dp[a][b]=mn;
 
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("out1.txt", "w", stdout);
#endif
  ll i, j;
  ll n , m, c = 0;
  cin >> n >> m;
 
  memset(dp,-1,sizeof(dp));
  cout<<rect(n,m);
 
  return 0;
}
