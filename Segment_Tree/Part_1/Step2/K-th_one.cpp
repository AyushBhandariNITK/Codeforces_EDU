    #include<bits/stdc++.h>
    using namespace std;
    #define loop(i,k,n) for(int i=k;i<n;++i)
    #define loopr(i,k,n) for (int i=k;i>n;--i)
    #define loopeq(i,k,n) for(int i=k;i<=n;++i)
    #define loopeqr(i,k,n) for(int i=k;i>=n;--i)
    #define  ll long long int 
    #define ff first
    #define ss second
    #define pll pair<ll,ll>
    #define pii pair<int,int>
    #define pb push_back
    #define vl vector<ll>
    #define vi vector<int>
    #define mp make_pair
    #define M 1e9+7
    #define time        cerr << "\nTime elapsed: " << 1000 * clock()
    #define inf 1e18
    typedef int item ;
    struct segtree{
        int size;
        vector<ll> sums,mins;
        vector<item> values;
        item NEUTRAL_ELEMENT=0;     //doesn't change result
        item single(int v)
        {
            return v;
        }
        item merge(item a ,item b)
        {
            return a+b;
        }
        void init(int n)
        {
            size=1;
            while(size<n)
                size*=2;
            sums.assign(2*size,0LL);
            mins.assign(2*size,inf);
            values.resize(2*size);
        }
        void set(int i,int v,int x,int lx,int rx)
        {
            if(rx-lx==1)
            {
                sums[x]=v;
                mins[x]=v;
                values[x]=single(v);
                return ;
            }
            int m=(lx+rx)/2;
            if(i<m)
                set(i,v,2*x+1,lx,m);
            else
                set(i,v,2*x+2,m,rx);
            sums[x]=sums[2*x+1]+sums[2*x+2];
            mins[x]=min(mins[2*x+1],mins[2*x+2]);
            values[x]=merge(values[2*x+1],values[2*x+2]);
     
        }
        item calc(int l,int r,int x,int lx,int rx)
        {
            if(r<=lx||rx<=l)
                return NEUTRAL_ELEMENT;
            if(l<=lx&&r>=rx)
                return values[x];
            int m=(lx+rx)/2;
            item s1=calc(l,r,2*x+1,lx,m);
            item s2=calc(l,r,2*x+2,m,rx);
            return merge(s1,s2);      
        }
        item calc(int l,int r)
        {
            return calc(l,r,0,0,size);
        }
        void set(int i,int v)
        {
            set(i,v,0,0,size);
        }
        ll minimum(int l,int r,int x,int lx,int rx)
        {
            if(r<=lx||rx<=l)
                return inf;
            if(l<=lx&&r>=rx)
                return mins[x];
            int m=(lx+rx)/2;
            ll leftmin=minimum(l,r,2*x+1,lx,m);
            ll rightmin=minimum(l,r,2*x+2,m,rx);
            return min(leftmin,rightmin);        
        }
        ll minimum(int l,int r)
        {
            return minimum(l,r,0,0,size);
        }
        ll sum(int l,int r,int x,int lx,int rx)
        {
            if(r<=lx||rx<=l)
                return 0;
            if(l<=lx&&r>=rx)
                return sums[x];
            int m=(lx+rx)/2;
            ll sumleft=sum(l,r,2*x+1,lx,m);
            ll sumright=sum(l,r,2*x+2,m,rx);
            return sumleft+sumright;
        }
        ll sum(int l,int r)
        {
            return sum(l,r,0,0,size);
        }
        void build(vector<int>&a,int x,int lx,int rx)
        {
            if(rx-lx==1)
            {
                if(lx<a.size())
                {
                    sums[x]=a[lx];
                    mins[x]=a[lx];
                    values[x]=single(a[lx]);
                }
                return;
            }
            int m=(lx+rx)/2;
            build(a,2*x+1,lx,m);
            build(a,2*x+2,m,rx);
            sums[x]=sums[2*x+1]+sums[2*x+2];
            mins[x]=min(mins[2*x+1],mins[2*x+2]);
            values[x]=merge(values[2*x+1],values[2*x+2]);
     
        }
        void build(vector<int>&a)
        {
            build(a,0,0,size);
        }
        int find(int k,int x,int lx,int rx)
        {
            if(rx-lx==1)
                return lx;
            int m=(lx+rx)/2;
            int s1=values[2*x+1];
            if(k<s1)
                return find(k,2*x+1,lx,m);
            return find(k-s1,2*x+2,m,rx);
        }
        int find(int k)
        {
            return find(k,0,0,size);
        }
    };
    int main()
    {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n,m;
        cin>>n>>m;
        segtree st;
        st.init(n);
        vector<int> arr(n);
        loop(i,0,n)
            cin>>arr[i];
        st.build(arr);
       // cout<<st.calc(0,n).seg<<"\n";
        int op,x,y;
        while(m--)
        {
            cin>>op;
            if(op%2)
            {
                int i;
                cin>>i;
                arr[i]=1-arr[i];
                st.set(i,arr[i]);
            }
            else
            {
                int k;
                cin>>k;
                cout<<st.find(k)<<"\n";
            }
     
        }
    }