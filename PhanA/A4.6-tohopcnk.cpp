#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int base = 1e9 + 7;
ll f[1005][1005];
int main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int test; cin >> test;
	
	for(int i = 0 ; i <= 1000 ;i++)
		f[0][i] = 1;
	for(int j = 1 ; j <= 1000 ; j++) {
		for(int i = 1 ; i <= j ; i++) {
			f[i][j] = ( f[i][j-1] + f[i-1][j-1] );
			f[i][j] %= base;
		}
	}
	while(test--) {
		int n , k;
		cin >> n >> k;
		cout << f[k][n] << endl;
	}


}






