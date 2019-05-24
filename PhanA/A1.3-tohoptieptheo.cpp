#include <iostream>
#include <cstring>
using namespace std;

void next(int a[], int n, int k){
	int i = k;
	while( i > 0 && a[i] == n - k + i ) i--;	// step 1
	if( i > 0 ){
		a[i]++;	// step 2
		i++;
		while( i <= k ){	// step 3
			a[i] = a[i-1] + 1;
			i++;
		}
	}
}

int main()
{
	int t, n, k;
	int a[50], d[50];
	cin>>t;
	while( t-- ){
		cin>>n>>k;
		memset(a, 0, sizeof(a));
		memset(d, 0, sizeof(d));
		for(int i=1; i<=k; i++){
			cin>>a[i];
			d[ a[i] ]++;
		}
		next(a, n, k);
		int res = 0;
		for(int i=1; i<=k; i++){
			if( d[ a[i] ] == 0 ) res++;	// cac so nay duoc thay vao
		}
		if( res == 0 ) res = k;
		cout<<res<<endl;
	}
}
