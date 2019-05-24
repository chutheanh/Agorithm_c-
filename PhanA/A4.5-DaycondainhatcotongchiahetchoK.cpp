#include<bits/stdc++.h>
#define for0(i,n) for (i=0;i<n;++i)
#define for1(i,n) for (i=1;i<=n;++i)
#define forlr(i,l,r) for (i=l;i<=r;++i)
#define ford(i,n) for (i=n-1;i>=0;--i)
#define pb push_back
#define ll long long
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define INF 1000000000
#define N 1005
#define KK 55
 
using namespace std;
int f[N][KK], n, k, a[N],i,j;
 
int main() {
 
	ll s = 0;
	cin>>n>>k;
	for1(i,n) { cin>>a[i]; s = (s+a[i])%k; }
	f[0][0] = 0; for1(i,k-1) f[0][i] = INF;
	for1(i,n) for0(j,k)
		f[i][j] = min(f[i-1][j], f[i-1][((j-a[i])%k+k)%k]+1);
	cout<<n-f[n][s%k];
	return 0;
} 
