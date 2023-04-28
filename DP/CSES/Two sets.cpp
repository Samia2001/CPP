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
ll a[505],ans,n,dp[502][62630],mod=1e9+7;
ll subset_sum(ll sum,ll i)
{
  rep(i,sum+1)
  dp[0][i]=0;
  
  dp[0][0]=1;
  for(ll i = 1;i<n;i++)
  {
    for(ll s=0;s<=sum;s++)
    {
      dp[i][s]=dp[i-1][s];
      if(s-a[i]>=0)
      dp[i][s]=(dp[i][s]+dp[i-1][s-a[i]])%mod;
    }
  }
   return dp[n-1][sum];
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("outp1.txt", "w", stdout);
#endif
  ll i;
  cin >> n;
  rep1(i,n)
  {
    a[i]=i;
  }
  memset(dp,-1,sizeof(dp));
  ll p = (n*(n+1))/2;
  if(p%2)
    cout<<0;
  else
  cout<<subset_sum(p/2 , 1);
 
 
  return 0;
}
