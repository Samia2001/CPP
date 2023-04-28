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
ll n ,m;
ll dp[1001][100005];
ll book(ll p[],ll pg[])
{
  ll i ,j;
  rep(i , n+1)
  dp[i][0]=0;
  rep(i , m+1)
  dp[0][i]=0;
 
  rep1(i , n)
  {
    rep1(j , m)
    {
 
      if(j>=p[i])
      {
        dp[i][j]=max(dp[i-1][j],dp[i-1][j-p[i]]+pg[i]);
        
      }
      else
        dp[i][j]=dp[i-1][j];
    }
  }
  return dp[n][m];
 
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("outp1.txt", "w", stdout);
#endif
  ll i , j , k;
  nml {
    
    cin >> n >> m;
    ll p[n+5],pg[n+5];
    rep1(i , n)
    cin >> p[i];
    rep1(i , n)
    cin >> pg[i];
    cout<<book(p,pg);
 
 
    
  }
 
 
  return 0;
}
