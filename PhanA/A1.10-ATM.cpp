#include <iostream>
#include <algorithm>
using namespace std;

int n, s;
int t[40];
int res = -1, sum = 0, tmp = 0;

void init(){
	cin>>n>>s;
	for(int i=1; i<=n; i++) cin>>t[i];
	sort(t+1, t+1+n, greater<int>() );	// xep giam dan
}

void Try(int i){
	for(int j=s/t[i]; j>=0; j--){	// so to tien t[i]
		tmp += j;	// so to tien
		s -= j * t[i];	// so tien con lai
		if( i < n ){
			sum = tmp + s / t[i+1];	// tong so to tien co the co
			if( sum <= res || res == -1 ) Try(i+1);
		}
		else if( s == 0 ){
			if( res == -1 || tmp < res ) res = tmp;
		}
		s += j * t[i];
		tmp -= j;
	}
}

int main()
{
	init();
	Try(1);
	cout<<res;
}
