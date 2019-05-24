#include <iostream>
using namespace std;

int n, k, count, sum;
int a[15][15], d[15], b[15];
int res[35000][15];

void init(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++) cin>>a[i][j];
	}
}

void Try(int i){
	for(int j=1; j<=n; j++){
		if( d[j] == 0 ){
			b[i] = j;
			sum += a[i][j];
			d[j] = 1;
			if( sum <= k && i < n ) Try(i+1);
			else if( sum == k && i == n ){
				for(int r=1; r<=n; r++) res[count][r] = b[r];
				count++;
			}
			sum -= a[i][j];
			d[j] = 0;
		}
	}
}

int main()
{

	cin>>n>>k;
	init();
	Try(1);
	cout<<count;
	for(int i=0; i<count; i++){
		cout<<endl;
		for(int j=1; j<=n; j++){
			cout<<res[i][j]<<" ";
		}
	}
}
