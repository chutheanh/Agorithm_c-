#include <iostream>
using namespace std;

int n, k, dem, x[100];
bool cot[100], xuoi[100], nguoc[100], d[100];

void set(int i){
	for(int j=1; j<=n; j++){
		if( !cot[j] && !xuoi[i-j+n] && !nguoc[i+j-1] ){
			cot[j] = true;
			xuoi[i-j+n] = true;
			nguoc[i+j-1] = true;
			if( i==n ) dem++;
			else set(i+1);
			cot[j] = false;
			xuoi[i-j+n] = false;
			nguoc[i+j-1] = false;
		}
	}
}

int main()
{
	cin>>n;
	set(1);
	cout<<dem;
}
