#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define loop(i,k,n) for(ll i=k;i<n;++i)
#define loopr(i,k,n) for (ll i=k;i>n;--i)
#define loopeq(i,k,n) for(ll i=k;i<=n;++i)
#define loopeqr(i,k,n) for(ll i=k;i>=n;--i)
#define M 1000000007
#define ff first
#define ss second
#define pll pair<ll,ll>
#define pii pair<ll,ll>
#define pb push_back
#define vl vector<ll>
#define vi vector<ll>
#define mp make_pair
#define inf (ll)1e18
vector<int> final;
void seive(int n)
{
    vector<bool> prime(n+1,true);
    prime[0]=false;
    prime[1]=false;
    loopeq(i,2,(ll)sqrt(n))
    {
        if(prime[i])
        {
            for(int j=i*i;j<=n;j+=i)
                prime[j]=false;
        }
    }
    loopeq(i,2,n)
    {
        if(prime[i])
            final.pb(i);
    }

}
const int mod=998244353;
const int  mx =2e5+1;
vector<int> fact(mx);
vector<int> inv_fact(mx);
ll expo_pow(ll a,ll b)
{
    a%=mod;
    ll res=1;
    while(b)
    {
        if(b&1)
            res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }   
    return res;
}
void precompute() 
{ 
    fact[0]=1;
    loopeq(i,1,mx) fact[i]=(fact[i-1]*i)%mod;
    loopeq(i,0,mx) inv_fact[i]=expo_pow(fact[i],mod-2)%mod;
} 
ll compute(ll n,ll r)
{
    return fact[n]*1ll*inv_fact[r]%mod*inv_fact[n-r]%mod;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    loop(i,0,n)
        cin>>a[i];
    ll res=0,l=0,r=0;
    set<ll> s;
    map<ll,ll> m;
    while(r<n)
    {
        s.insert(a[r]);
        m[a[r]]++;
        while(s.size()>k)
        {
            m[a[l]]--;
            if(m[a[l]]==0)
                s.erase(a[l]);
            l++;
        }
        res+=r-l+1;
        r++;
    }
    cout<<res<<"\n";
}