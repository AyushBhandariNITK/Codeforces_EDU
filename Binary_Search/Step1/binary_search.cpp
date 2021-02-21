#include<bits/stdc++.h>
using namespace std;
#define loop(i,k,n) for(int i=k;i<n;++i)
#define loopr(i,k,n) for (int i=k;i>n;--i)
#define loopeq(i,k,n) for(int i=k;i<=n;++i)
#define loopeqr(i,k,n) for(int i=k;i>=n;--i)
#define  ll long long int 
#define M 1000000007
#define time        cerr << "\nTime elapsed: " << 1000 * clock()
int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	vector<int > arr(n);
	loop(i,0,n)
		cin>>arr[i];
	while(k--)
	{
		bool y=false;
		int l=0,x,r=n-1;
		cin>>x;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(arr[mid]>x)
				r=mid-1;
			else if(arr[mid]==x)
			{
				y=true;
				break;
			}
			else
				l=mid+1;
		}
		if(y)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}