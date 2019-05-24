#include <iostream>
using namespace std;

int bin_search(int a[], int l, int r, int k){
	int m = ( l + r ) / 2;
	while( l <= r ){
		if( a[m] == k ) return m;
		if( a[m] > k ) r = m - 1;
		else l = m + 1;
		m = ( l + r ) / 2;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	int t, n, k, a[100005];
	cin>>t;
	while( t-- ){
		cin>>n>>k;
		for(int i=1; i<=n; i++) cin>>a[i];
		int key = bin_search(a, 1, n, k);
		if( key == -1 ) cout<<"NO\n";
		else cout<<key<<endl;
	}
}
