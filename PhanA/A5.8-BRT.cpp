#include <iostream>
#include <algorithm>
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
		sort(a, a+n);
		int min_dis = 1e9, pair = 0;
		for(int i=1; i<n; i++){
			if( a[i] - a[i-1] < min_dis ) min_dis = a[i] - a[i-1];
		}
		for(int i=1; i<n; i++){
			if( a[i] - a[i-1] == min_dis ) pair++;
		}
		cout<<min_dis<<" "<<pair<<endl;
	}
}
