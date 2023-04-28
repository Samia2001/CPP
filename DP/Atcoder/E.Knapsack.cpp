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
ll n , W;
ll w[105],v[105];
 ll mxval=100001,dp[105][100005];
ll knapsack_big()
{
  ll i,j;
  rep(i , 102)
  dp[i][0]=0;

  rep1(i , n)
  {
    rep1(j , mxval)
    {

      if(j<v[i])
        dp[i][j]=dp[i-1][j];
      else
      {
        dp[i][j] = min(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
      }
    }
  }
  
  for(i = mxval;i>=0;i--)
  {

    if(dp[n][i]<=W)
      {//cout<<dp[n][i]<<endl;
      break;}
  }
 return i;

}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("out1.txt", "w", stdout);
#endif
  ll i,j;
  cin >> n >> W;
  rep1(i , n)
  {
    cin >> w[i] >> v[i];
  }
 
  for(i = 0;i<=101;i++)
  {
    for(j = 0;j<=100001;j++)
      dp[i][j]=1e18;
  }
  cout<<knapsack_big();

  return 0;
}
