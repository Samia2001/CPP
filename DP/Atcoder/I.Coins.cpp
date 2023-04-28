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
double dp[5000][5000],s=0;
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("out1.txt", "w", stdout);
#endif
  ll n,i,j;
  cin >> n;
  double p[n + 5];
  rep1(i , n)
  {
    cin >> p[i];
  }
  
  dp[0][0]=1;
  rep1(i , n)
  {
    dp[i][0]=dp[i-1][0]*(1-p[i]);
   for(j = 1;j<=i;j++)
   {
    
    dp[i][j]=dp[i-1][j-1]*p[i];
    if(dp[i-1][j])
      dp[i][j]+=dp[i-1][j]*(1-p[i]);


   }
  }
  for(i = n;i>n/2;i--)
  s+=dp[n][i];
cout<<fixed<<setprecision(15)<<s<<endl;
  return 0;
}
