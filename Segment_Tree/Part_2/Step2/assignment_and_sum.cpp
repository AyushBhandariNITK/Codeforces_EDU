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
	vector<ll> ops,values;
	ll NEUTRAL_ELEMENT=0;
	ll NO_OPERATION=LLONG_MAX-1;
	ll modify_op(ll a,ll b,ll len)
	{
		if(b==NO_OPERATION)
			return a;
		return b*len;		// bcuz we are changing the sum to some value rather than adding
	}
	ll calc_op(ll a,ll b)
	{
		return a+b;
	}
	void propagate(ll x,ll lx,ll rx)
	{
		if(rx-lx==1)
			return;
		ll m=(lx+rx)/2;
		apply_mod_op(ops[2*x+1],ops[x],1);
		apply_mod_op(values[2*x+1],ops[x],m-lx);
		apply_mod_op(ops[2*x+2],ops[x],1);
		apply_mod_op(values[2*x+2],ops[x],rx-m);
		ops[x]=NO_OPERATION;
	}
	void apply_mod_op(ll &a,ll b,ll len)
	{
		a=modify_op(a,b,len);
	}
	void init(ll n)
	{
		size=1;
		while(size<n)
			size*=2;
		ops.assign(2*size,0LL);
		values.assign(2*size,0LL);
	}
	void modify(ll l,ll r,ll v)
	{
		modify(l,r,v,0,0,size);
	}
	void modify(ll l,ll r,ll v,ll x,ll lx,ll rx)
	{
		propagate(x,lx,rx);
		if(lx>=r||rx<=l)
			return ;
		if(l<=lx&&rx<=r)
		{
			apply_mod_op(ops[x],v,1);
			apply_mod_op(values[x],v,rx-lx);
			return ;
		}
		ll m=(lx+rx)/2;
		modify(l,r,v,2*x+1,lx,m);
		modify(l,r,v,2*x+2,m,rx);
		values[x]=calc_op(values[2*x+1],values[2*x+2]);
		//apply_mod_op(values[x],ops[x],rx-lx);  bcuz propagation push operation downward
	}
	ll calc(ll l,ll r)
	{
		return calc(l,r,0,0,size);
	}
	ll calc(ll l,ll r,ll x,ll lx,ll rx)
	{
		propagate(x,lx,rx);
		if(lx>=r||rx<= l)
			return NEUTRAL_ELEMENT;
		if(l<=lx&&rx<=r)
			return values[x];
		ll m=(lx+rx)/2;
		ll left=calc(l,r,2*x+1,lx,m);
		ll right=calc(l,r,2*x+2,m,rx);
		return calc_op(left,right);
		//apply_mod_op(res,ops[x],min(rx,r)-max(lx,l));			
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
    		st.modify(l,r,v);
    	}
    	else
    	{
    		cout<<st.calc(l,r)<<"\n";
    	}
    }

}
