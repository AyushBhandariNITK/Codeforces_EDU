#include<bits/stdc++.h>
using namespace std;
#define loop(i,k,n) for(int i=k;i<n;++i)
#define loopr(i,k,n) for (int i=k;i>n;--i)
#define loopeq(i,k,n) for(int i=k;i<=n;++i)
#define loopeqr(i,k,n) for(int i=k;i>=n;--i)
#define  ll long long int 
#define M 1000000007
#define ff first
#define ss second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pb push_back
#define vl vector<ll>
#define vi vector<int>
#define mp make_pair
#define M 1000000007
#define time 1000 * clock()
#define inf 1e18
bool check(ll x,ll a,ll b,ll n)
{
    return ((x/a)*(x/b))>=n;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,n,l=0,r=1; // l is bad 
    cin>>a>>b>>n;
    while(!check(r,a,b,n))
        r*=2;           // r will be good
    
    while(l+1<r)        
    {
        ll mid=(l+r)/2;
        if(check(mid,a,b,n))
            r=mid;
        else
            l=mid;
    }
    cout<<r<<"\n";
    
}