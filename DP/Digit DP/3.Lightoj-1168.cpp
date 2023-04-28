#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;
 
ll k;
vector<ll>digit ;
ll dp[11][2][99][99] ;
ll po[11] ;
ll sol(ll pos, bool is_small, ll sum, ll till_mod) {
	if(pos >= digit.size()) {
		if(sum%k==0 && till_mod==0) return 1 ;
		return 0 ;
	}
	
	if(dp[pos][is_small][sum][till_mod]!=-1) 
		return dp[pos][is_small][sum][till_mod] ;
	
	ll limit = digit[pos] ;
	if(is_small) limit=9 ;
	
	ll val = 0 ;
	for(int i=0; i<=limit; i++) {
		ll tm = (till_mod + (i*po[(ll)digit.size()-pos-1])%k)%k ;
		val += sol(pos+1, i<digit[pos]|is_small, sum+i, tm) ;
	}
	
	return dp[pos][is_small][sum][till_mod] = val ;
}

void convert(ll x) {
	while(x) {
		digit.push_back(x%10) ;
		x/=10; 
	}
	reverse(digit.begin(), digit.end()) ;
}
 
int main() {
	// your code goes here
	po[0]=1 ;
	for(int i=1; i<=10; i++)
		po[i] = po[i-1]*10 ;
	
	ll tc, z=1 ;
	cin >> tc ;
	while(tc--) {
		ll a, b ;
		cin >> a >> b >> k ;
		
		ll r, l ;
		convert(b) ;
		memset(dp, -1, sizeof dp) ;
		r = sol(0, 0, 0, 0) ;
		digit.clear() ;
		
		convert(a-1) ;
		memset(dp, -1, sizeof dp) ;
		l = sol(0, 0, 0, 0) ;
		digit.clear() ;
		cout << "Case " << z++ << ": " << r-l << endl ;
	}
	return 0;
}
