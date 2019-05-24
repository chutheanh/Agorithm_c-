#include <iostream>
using namespace std;

int lap = 0;
bool res[35000][20];

void print(bool a[], int n) {
	cout<<endl;
	for(int i=1; i<=n; i++) {
		if( a[i] ) cout<<'B';
		else cout<<'A';
	}
}

void Try(int i, int n, int k, bool a[], int dem[], int &count) {
	for(int j=0; j<2; j++) {
		a[i] = j;
		if( !a[i] ) dem[i] = dem[i-1] + 1;	// chon bit 0
		if( dem[i] <= k ) {
			if( dem[i] == k ) lap++;
			if( lap < 2 ) {
				if( i < n ) Try(i+1, n, k, a, dem, count);
				else if( lap == 1 ) {
					for(int i=1; i<=n; i++) {
						res[count][i] = a[i];
					}
					count++;
				}
			}
			if( dem[i] == k ) lap--;
		}
		if( !a[i] ) dem[i] = 0;		// khong chon bit 0
	}
}


int main() {
	int n, k;
	bool a[20] = {0};
	int count, dem[20] = {0};
	cin>>n>>k;
	count = 0;
	Try(1, n, k, a, dem, count);
	cout<<count;
	for(int i=0; i<count; i++) {
		print(res[i], n);
	}
}
