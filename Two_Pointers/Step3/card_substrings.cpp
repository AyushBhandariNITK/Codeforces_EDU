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
    ll t=1;
    //cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        string a,b;
        cin>>a>>b;
        vector<ll> cnt_a(26),cnt_b(26);
        loop(i,0,m)
            cnt_b[b[i]-'a']++;
        ll l=0,r=0,sum=0;
        while(r<n)
        {
            cnt_a[a[r]-'a']++;
            while(cnt_a[a[r]-'a']>cnt_b[a[r]-'a'])
            {
                cnt_a[a[l]-'a']--;
                l++;
            }
            sum+=(r-l+1);
            r++;
        }
        cout<<sum<<"\n";
    }

}
