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
bool check(vector<ll>&arr,double x,ll k)
{
    ll pieces=0;
    loop(i,0,arr.size())
        pieces+=(arr[i]/x);
    return pieces>=k;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double n,k;
    cin>>n>>k;
    vector<ll> arr(n);
    loop(i,0,n)
        cin>>arr[i];
    sort(arr.begin(),arr.end());
    double l=0.0,r=1.0;
    while(check(arr,r,k))
        r*=2.0;         // here r will be bad
    loop(i,1,100)
    {
        double m=(l+r)/2;
        if(check(arr,m,k))
            l=m;
        else
            r=m;
    }
    cout<<setprecision(20)<<l<<"\n";      // as l is good here
}