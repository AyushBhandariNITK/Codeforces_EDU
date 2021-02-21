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
#define inf 3e9
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,x;
    cin>>n>>k;
    vector<ll>arr(n+2);
    arr[0]=-inf;
    arr[n+1]=inf;
    loopeq(i,1,n)
        cin>>arr[i];
    while(k--)
    {
        int l=-1,r=n,mid,ans=0;
        cin>>x;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(arr[mid]>x)
                r=mid-1;
            else
            {
                ans=mid;
                l=mid+1;
            }
        }
        cout<<ans<<"\n";
    }
}