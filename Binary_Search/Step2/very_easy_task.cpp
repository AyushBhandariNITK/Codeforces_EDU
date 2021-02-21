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
// have to find time when there are n copies of original not including original paper
bool check(ll t,ll n,ll x,ll y)
{
    return (t/x)+((t-x)/y)>=n;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x,y,l=0,r=1;
    cin>>n>>x>>y;
    if(x>y)
        swap(x,y);
    while(!check(r,n,x,y))
        r*=2;
    while(l+1<r)
    {
        ll m=(l+r)/2;
        if(check(m,n,x,y))
            r=m;
        else
            l=m;
    }
    cout<<r<<"\n";
}