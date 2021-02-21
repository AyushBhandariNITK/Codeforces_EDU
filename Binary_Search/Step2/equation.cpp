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
bool check(double x,double c)
{
    return (x*x + sqrt(x))>=c;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double l=0.0,r=1.0,c;
    cin>>c;
    while(!check(r,c))
        r*=2.0;
    loop(i,0,100)
    {
        double m=(l+r)/2;
        if(check(m,c))
            r=m;
        else
            l=m;
    }
    cout<<setprecision(20)<<r<<"\n";
}