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
#define inf 1e18
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n;
    vector<ll> arr(n+2);
    arr[0]=-inf;
    arr[n+1]=inf;
    loopeq(i,1,n)
        cin>>arr[i];
    sort(arr.begin(),arr.end());
    cin>>k;
    while(k--)
    {
        int l=-1,r=n,mid,ans1=0;
        int left,right;
        cin>>left>>right;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(arr[mid]>right)
                r=mid-1;
            else
            {
                ans1=mid;
                l=mid+1;
            }
        }
        l=-1,r=n;
        int ans2=n+1;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(arr[mid]>=left)
            {
                ans2=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        cout<<ans1-ans2+1<<" ";
    }
}