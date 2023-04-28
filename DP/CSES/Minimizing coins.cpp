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
ll coin(ll n , ll m ,ll c[])
{
  ll dp[m+1],i,j;
  
  rep(i , m+1)
  dp[i]=1e18;
 
  dp[0]=0;
 
  for(i = 1;i<n+1;i++)
  {
     for(j = 1;j<m+1;j++)
    {
      
      if(j>=c[i])
      {
        dp[j]=min(dp[j-c[i]]+1,dp[j]);
      }
    }
  }
  
  return dp[m];
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("outp1.txt", "w", stdout);
#endif
  ll i , j;
  nml {
    ll n , m;
    cin >> n >> m;
    ll c[n+5];
    rep1(i,n)cin>>c[i];
    sort(c+1,c+n+1);
    ll p = coin(n, m,c);
    if(p==1e18)cout<<-1<<endl;
    else
    cout << p << endl;
 
  }
  return 0;
}
