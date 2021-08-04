#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
#define endl "\n"
#define    rep(X,Y)     for(X=0;X<Y;X++)
#define    rep1(X,Y)    for(X=1;X<=Y;X++)
#define    rrep(X,Y)    for(X=Y-1;X>=0;X--)
#define    rrep1(X,Y)   for(X=Y;X>=1;X--)
#define ml ll T,g; cin>>T; for(g=0;g<T;g++)
#define case "Case "<<g+1<<": "
#define sf(T) scanf("%lld",&T)
#define pf(T) printf("%lld\n",T)
#define      len(n)             (long long)((log(n)/log(10))+1.0000000001)
#define FastRead                      \
                                    ios_base::sync_with_stdio(false); \
                                    cin.tie(0);
#define pi acos(-1)
#define pb push_back
#define pll pair<ll , ll>
#define pqmn priority_queue<ll, vector<ll>, std::greater<ll> >
#define nm -1e18
#define ok return 0

using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,greater_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

string s[500][500];

string lng_cs(string a,string b,ll n,ll m)
{
    ll i,j;

    ll L[500][500];


    for(i=0; i<=n; i++)
    {
        for(j=0; j<=m; j++)
        {
            if(i==0 || j==0)
            {
                L[i][j]=0;
                s[i][j]="";
            }
            else if(a[i-1]==b[j-1])
            {
                L[i][j]=L[i-1][j-1]+1;
                s[i][j] = s[i-1][j-1]+a[i-1];
            }
            else
            {
                L[i][j]=max(L[i-1][j],L[i][j-1]);

                if(L[i-1][j]>L[i][j-1])
                {
                    s[i][j] = s[i-1][j];
                }
                else if(L[i-1][j]<L[i][j-1])
                {
                    s[i][j] = s[i][j-1];
                }
                else
                {
                    s[i][j] = min (s[i-1][j] , s[i][j-1]);
                }

            }
        }

    }

    return s[n][m];

}
int main()
{
    FastRead
    ml
    {
        string a, b , c;
        ll i, len, n, m;

        cin >> a >> b;
        n = a.size();
        m = b.size();

        c = lng_cs(a,b,n,m);

        if(c=="")
            cout<<case<<":(";
        else
            cout<<case<<c;
        cout<<endl;

    }
    return 0;
}

