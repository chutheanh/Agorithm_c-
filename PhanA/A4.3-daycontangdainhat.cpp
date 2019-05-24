#include<bits/stdc++.h>
using namespace std;
main(){
	int n, a[1001], f[1001],i,j;
	cin >> n;
	for(i=0; i<n; i++){
		cin >> a[i];
		f[i]=1;
		for(j=0; j<i; j++){
			if(a[i] > a[j] ) f[i] = max (f[i],f[j]+1);
		}
	}
	sort(f,f+n);
	cout << f[n-1];
 
} 
