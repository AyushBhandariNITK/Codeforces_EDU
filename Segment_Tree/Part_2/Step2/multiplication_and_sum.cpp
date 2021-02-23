#include<bits/stdc++.h>
using namespace std;
#define  ll long long int 
#define loop(i,k,n) for(ll i=k;i<n;++i)
#define loopr(i,k,n) for (ll i=k;i>n;--i)
#define loopeq(i,k,n) for(ll i=k;i<=n;++i)
#define loopeqr(i,k,n) for(ll i=k;i>=n;--i)
#define ff first
#define ss second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pb push_back
#define vl vector<ll>
#define vi vector<int>
#define mp make_pair
#define M 1000000007
#define inf 1e18
struct segtree
{
	ll size;
	vector<ll> values,mul;
	void build(ll x,ll lx,ll rx)
	{
		if(rx-lx==1)
		{
			values[x]=1;
			return ;
		}
		ll m=(lx+rx)/2;
		build(2*x+1,lx,m);
		build(2*x+2,m,rx);
		values[x]=(values[2*x+1]+values[2*x+2])%M;
	}
	void init(ll n)
	{
		size=1;
		while(size<n)
			size*=2;
		values.assign(2*size,0LL);
		mul.assign(2*size,1LL);
		build(0,0,size);
	}
	void multiply(ll l,ll r,ll v)
	{
		multiply(l,r,v,0,0,size);
	}
	void multiply(ll l,ll r,ll v,ll x,ll lx,ll rx)
	{
		if(lx>=r||rx<=l)
			return ;
		if(l<=lx&&rx<=r)
		{
			mul[x]=(mul[x]*v)%M;
			values[x]=(values[x]*v)%M;
			return ;
		}
		ll m=(lx+rx)/2;
		multiply(l,r,v,2*x+1,lx,m);
		multiply(l,r,v,2*x+2,m,rx);
		values[x]=(values[2*x+1]%M+values[2*x+2]%M)%M;
		values[x]=(values[x]*mul[x])%M;
	}
	ll get_sum(ll l,ll r)
	{
		return get_sum(l,r,0,0,size);
	}
	ll get_sum(ll l,ll r,ll x,ll lx,ll rx)
	{
		if(lx>=r||rx<=l)
			return 0;
		if(l<=lx&&rx<=r)
		{
			return values[x]%M;
		}
		ll m=(lx+rx)/2;
		ll left=get_sum(l,r,2*x+1,lx,m)%M;
		ll right=get_sum(l,r,2*x+2,m,rx)%M;
		return ((left+right)*mul[x])%M;
	}
	void print()
	{
		loop(i,0,values.size())
			cout<<values[i]<<" ";
		cout<<"\n";
	}
};
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,v;
    cin>>n>>m;
    segtree st;
    st.init(n);
    while(m--)
    {
    	ll op,l,r;
    	cin>>op>>l>>r;
    	if(op==1)
    	{
    		cin>>v;
    		st.multiply(l,r,v);
    	}
    	else
    		cout<<st.get_sum(l,r)<<"\n";
    }

}
