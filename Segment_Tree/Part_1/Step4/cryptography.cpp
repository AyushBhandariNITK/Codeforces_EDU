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
    struct item
    {
        int a[2][2]={{0,0},{0,0}};
    };
    struct segtree{
        int size,mod;
        vector<item> sums;
        item NEUTRAL_ELEMENT={{{1,0},{0,1}}};
        //Make size in power of 2
        void init(int n,int r)    
        {
            mod=r;
            size=1;
            while(size<n)
                size*=2;
            sums.assign(2*size,NEUTRAL_ELEMENT);
        }
        void set(int i,item v)
        {
            set(i,v,0,0,size);
        }
        item sum(int l,int r)
        {
           return sum(l,r,0,0,size);
        }
        item merge(item x,item y)
        {
            item final;
            loop(i,0,2)
            {
                loop(j,0,2)
                {
                    loop(k,0,2)
                        final.a[i][j]+=(x.a[i][k]) * (y.a[k][j]);
                    final.a[i][j]%=mod;
                }

            }   
            return final;         
        }
        void build(vector<item>&a)
        {
            build(a,0,0,size);
        }
        void build(vector<item>&a,int x,int lx,int rx)
        {
            if(rx-lx==1)
            {
                if(lx<a.size())
                    sums[lx]=a[lx];
                return ;
            }
            int m=(lx+rx)/2;
            build(a,2*x+1,lx,m);
            build(a,2*x+2,m,rx);
            sums[x]=merge(sums[2*x+1],sums[2*x+2]);
        }
        // curr=x,lx=left bound,rx=right bound
        void set(int i,item v,int x,int lx,int rx)
        {
            if(rx-lx==1)
            {
                sums[x]=v;
                return;
            }
            int m=(lx+rx)/2;
            if(i<m)
                set(i,v,2*x+1,lx,m);
            else
                set(i,v,2*x+2,m,rx);
            sums[x]=merge(sums[2*x+1],sums[2*x+2]);

        }
        item sum(int l,int r,int x,int lx,int rx)
        {
            if(rx<=l||lx>=r)
                return NEUTRAL_ELEMENT;
            if(lx>=l&&rx<=r)
                return sums[x];
            int m=(lx+rx)/2;
            item sleft=sum(l,r,2*x+1,lx,m);
            item sright=sum(l,r,2*x+2,m,rx);
            return merge(sleft,sright);
        }
        void print(item curr)
        {
            loop(i,0,2)
            {
                loop(j,0,2)
                    cout<<curr.a[i][j]<<" ";
                cout<<"\n";
            }
            cout<<"\n";
        }

    };
    int main()
    {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int r,a,b,n,m;
        cin>>r>>n>>m;
        vector<item> arr(n);
        segtree st;
        st.init(n,r);
        loop(i,0,n)
        {
            loop(j,0,2)
                loop(k,0,2)
                    cin>>arr[i].a[j][k];
            st.set(i,arr[i]);
        }      
        while(m--)
        {
            cin>>a>>b;
            item curr=st.sum(a-1,b);
            st.print(curr);        
        }

    }

