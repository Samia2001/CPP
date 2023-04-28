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
ll a[5005],dp[100005],mn=1e18,k,n;
ll call(ll baki)
{
  ll i;
  if(baki<0)
    return 0;
  if(baki<mn)
    return 1;
  if(dp[baki]!=-1)
    return dp[baki];
  ll ans = 0;
  for(i = 0;i<n;i++)
    ans = (ans |call(baki-a[i]));

  return dp[baki] = !ans;

}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("out1.txt", "w", stdout);
#endif
  ll i, j;
  nml{
   
    cin >> n >> k;
    rep(i , n)
    {
      cin >> a[i];
      dp[a[i]]=0;
      mn= min(mn,a[i]);
      
    }
    memset(dp,-1,sizeof(dp));
   if(!call(k))cout<<"First"<<endl;
   else cout<<"Second"<<endl;
   
  }

  return 0;
}
