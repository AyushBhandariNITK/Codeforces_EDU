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
    struct segtree{
        int size;
        vector<ll> sums,final;
        //Make size in power of 2
        void init(int n)    
        {
            size=1;
            while(size<n)
                size*=2;
            sums.assign(2*size,0LL);
            //mins.assign(2*size,inf);
            //values.resize(2*size);
        }

        void set(int i,int v)
        {
            set(i,v,0,0,size);
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
                    sums[lx]=a[lx];
                    //mins[lx]=a[lx];
                    //values[x]=single(a[lx]);
                }
                return;
            }
            int m=(lx+rx)/2;
            build(a,2*x+1,lx,m);
            build(a,2*x+2,m,rx);
            sums[x]=sums[2*x+1]+sums[2*x+2];
            //mins[x]=min(mins[2*x+1],mins[2*x+2]);
            //values[x]=merge(values[2*x+1],values[2*x+2]);

        }
        // curr=x,lx=left bound,rx=right bound
        void set(int i,int v,int x,int lx,int rx)
        {
            if(rx-lx==1)
            {
                sums[x]=v;
                //mins[x]=v;
                //values[x]=single(v);
                return;
            }
            int m=(lx+rx)/2;
            if(i<m)
                set(i,v,2*x+1,lx,m);
            else
                set(i,v,2*x+2,m,rx);
            sums[x]=sums[2*x+1]+sums[2*x+2];
            //mins[x]=min(mins[2*x+1],mins[2*x+2]);
            //values[x]=merge(values[2*x+1],values[2*x+2]);
        }
        ll sum(int l,int r,int x,int lx,int rx)
        {
            if(rx<=l||lx>=r)
                return 0;
            if(lx>=l&&rx<=r)
                return sums[x];
            int m=(lx+rx)/2;
            ll sleft=sum(l,r,2*x+1,lx,m);
            ll sright=sum(l,r,2*x+2,m,rx);
            return sleft+sright;
        }
        ll calc(int x)
        {
            return sum(x,size,0,0,size);
        }

    };
    int main()
    {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n,x;
        cin>>n;
        vector<ll> final(n),visit(n,-1);
        segtree st;
        st.init(2*n);
        loop(i,0,2*n)
        {
            cin>>x;
            x--;
            if(visit[x]==-1)
                visit[x]=i;
            else
            {
                final[x]=st.sum(visit[x],i);
                st.set(visit[x],1);
            }
        }
        loop(i,0,final.size())
            cout<<final[i]<<" ";


    }

