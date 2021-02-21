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
struct coprime
{
    vector<ll> s,values={0};
    void push(ll x)
    {
        s.push_back(x);
        values.push_back(__gcd(values.back(),x));
    }
    ll pop()
    {
        ll res=s.back();
        s.pop_back();
        values.pop_back();
        return res;
    }
    ll gcd()
    {
        return values.back();
    }
    bool empty()
    {
        return s.empty();
    }
};
coprime s1,s2;
void add(ll x)
{
    s2.push(x);
}
void remove()
{
    if(s1.empty())
    {
        while(!s2.empty())
        {
            s1.push(s2.pop());
        }
    }
    s1.pop();
}
bool good()
{
    ll g1=s1.gcd();
    ll g2=s2.gcd();
    //cout<<g1<<" "<<g2<<" ";
    return __gcd(g1,g2)==1;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> a(n);
    loop(i,0,n)
        cin>>a[i];
    ll res=inf,l=0,r=0;
    while(r<n)
    {
        add(a[r]);
        while(good())
        {
            remove();
            res=min(res,r-l+1);
            l++;
        }
        r++;
    }
    if(res==inf)
        res=-1;
    cout<<res<<"\n";
}
