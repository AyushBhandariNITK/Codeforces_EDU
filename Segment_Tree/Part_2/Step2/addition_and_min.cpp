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
#define M 1e9+7
#define inf 1e18
struct segtree
{
	ll size;
	vector<ll> ops,mins;
	void init(ll n)
	{
		size=1;
		while(size<n)
			size*=2;
		ops.assign(2*size,0LL);
		mins.assign(2*size,0LL);
	}
	void add(ll l,ll r,ll v)
	{
		add(l,r,v,0,0,size);
	}
	void add(ll l,ll r,ll v,ll x,ll lx,ll rx)
	{
		if(lx>=r||rx<=l)
			return ;
		if(l<=lx&&rx<=r)
		{
			ops[x]+=v;
			mins[x]+=v;
			return ;
		}
		ll m=(lx+rx)/2;
		add(l,r,v,2*x+1,lx,m);
		add(l,r,v,2*x+2,m,rx);
		mins[x]=ops[x]+min(mins[2*x+1],mins[2*x+2]);
	}
	ll minimum(ll l,ll r)
	{
		return minimum(l,r,0,0,size);
	}
	ll minimum(ll l,ll r,ll x,ll lx,ll rx)
	{
		if(lx>=r||rx<=l)
			return inf;
		if(l<=lx&&rx<=r)
			return mins[x];
		ll m=(lx+rx)/2;
		ll left=minimum(l,r,2*x+1,lx,m);
		ll right=minimum(l,r,2*x+2,m,rx);		
		return ops[x]+min(left,right);
	}
	ll get(ll i)
	{
		return get(i,0,0,size);
	}
	ll get(ll i,ll x,ll lx,ll rx)
	{
		if(rx-lx==1)
		{
			return ops[x];
		}
		ll res;
		ll m=(lx+rx)/2;
		if(i<m)
			res=get(i,2*x+1,lx,m);
		else
			res=get(i,2*x+2,m,rx);
		return res+ops[x];		
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
    		st.add(l,r,v);
    	}
    	else
    	{
    
    		cout<<st.minimum(l,r)<<"\n";
    	}
    }

}
