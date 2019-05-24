#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int t, n, a[100001], sum;
	cin>>t;
	while( t-- ){
		cin>>n;
		sum = 0;
		int d[15] = {0}, du, key = -1, sl = -1;	
		for(int i=0; i<n; i++){
			cin>>a[i];
			d[ a[i] ]++;
			sum += a[i];
		}
		du = sum % 3;
		if( du != 0 ){
			for(int i=1; i<10; i++){
				if( ( i % 3 == du && d[i] > 0 ) || ( i % 3 == ( 2 * du % 3 ) && d[i] > 1 ) ){
					int tmp;
					if( i % 3 == du ) tmp = 1;
					else tmp = 2;
					if( tmp < n && (sl == -1 || sl > tmp) ){
						key = i;
						sl = tmp;
					}
				}
			}
			if( key == -1 ) cout<<-1;
			else{
				sort(a, a+n, greater<int>());
				for(int i=0; i<n; i++){
					if( a[i] == key && sl-- != 0 ) continue;
					cout<<a[i];
				}
			}
		}
		else{
			sort(a, a+n, greater<int>());
			for(int i=0; i<n; i++) cout<<a[i];
		}
		cout<<endl;
	}
}
