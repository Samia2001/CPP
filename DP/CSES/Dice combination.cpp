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
ll a[10],dp[1000005],mod=1e9+7;
ll dice(ll n)
{
  ll i;
  if(n==0)return 1;
  if(n<0)return 0;
  if(dp[n]!=-1)return dp[n];
  ll s = 0;
  rep1(i , 6)
  {
    s=(s+dice(n-a[i]))%mod;
  }
  return dp[n]=s;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("out1.txt", "w", stdout);
#endif
  ll i, j;
  ll n , m,c=0;
  cin >> n;
  rep1(i , 6)
  a[i]=i;
  memset(dp,-1,sizeof(dp));
  cout<<dice(n);
  return 0;
}
