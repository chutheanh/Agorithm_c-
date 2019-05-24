#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, a[100005];
	cin>>t;
	while( t-- ){
		cin>>n;
		for(int i=0; i<n; i++) cin>>a[i];
		int l_tmp = -1, r_tmp = -1, l, r;
		for(int i=0; i<n-1; i++){	// tim dinh dau tien bi fail
			if( a[i] > a[i+1] ){
				l_tmp = i;
				break;
			}
		}
		for(int i=n-1; i>0; i--){	// tim day dau tien bi fail
			if( a[i] < a[i-1] ){
				r_tmp = i;
				break;
			}
		}
		if( r_tmp == l_tmp ) cout<<"YES\n";
		else{
			r = l_tmp;
			for(int i=l_tmp+1; i<n; i++){	// tim dinh dau tien khong bi fail
				if( a[i] >= a[r] ){
					r = i;
					if( r > r_tmp ) break;
				}
				if( i == n - 1 ) r = i+1;	// khong tim duoc dinh can tim
			}
			l = r_tmp;
			for(int i=r_tmp-1; i>=0; i--){	// tim day dau tien khong bi fail
				if( a[i] <= a[l] ){
					l = i;
					if( l < l_tmp ) break;
				}
				if( i == 0 ) l = i-1;		// khong tim duoc day can tim
			}
			cout<<r-l-1<<endl;
		}
	}
}
