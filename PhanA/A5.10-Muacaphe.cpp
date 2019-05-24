#include <iostream>
#include <algorithm>
using namespace std;

void bin_search(int a[], int l, int r, int k){
	int m = ( l + r ) / 2, res = r;	// res = n: mac dinh cac so <= k
	while( l <= r ){	// tim so dau tien > k 
		if( a[m] > k ){
			r = m - 1;
			res = r;
		}
		else l = m + 1;
		m = ( l + r ) / 2;
	}
	cout<<res<<endl;
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	int n, x[100005], q, y;
	cin>>n;
	for(int i=1; i<=n; i++) cin>>x[i];
	sort(x+1, x+1+n);
	cin>>q;
	while( q-- ){
		cin>>y;
		bin_search(x, 1, n, y);
	}
}
