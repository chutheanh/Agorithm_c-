#include <iostream>
#include <cstring>
using namespace std;

int t, n = 8, res, sum, x[10][10];
bool cot[10], xuoi[20], nguoc[20];

void init(){
	for(int i=1; i<=8; i++){
		for(int j=1; j<=8; j++) cin>>x[i][j];
	}
	sum = 0;
	res = 0;
	memset(cot, 0, sizeof(cot));
	memset(xuoi, 0, sizeof(xuoi));
	memset(nguoc, 0, sizeof(nguoc));
}

void set(int i){
	for(int j=1; j<=n; j++){
		if( !cot[j] && !xuoi[i-j+n] && !nguoc[i+j-1] ){
			sum += x[i][j];
			cot[j] = true;
			xuoi[i-j+n] = true;
			nguoc[i+j-1] = true;
			if( i==n ){
				if( res < sum ) res = sum;
			}
			else set(i+1);
			sum -= x[i][j];
			cot[j] = false;
			xuoi[i-j+n] = false;
			nguoc[i+j-1] = false;
		}
	}
}

int main()
{
	cin>>t;
	while( t-- ){
		init();
		set(1);
		cout<<res<<endl;
	}
}
