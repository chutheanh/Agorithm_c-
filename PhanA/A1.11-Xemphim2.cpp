#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int NMAX = 25000;
int C , N , a[105], f[105][NMAX+5];
void iNit() {
	cin >> C >> N;
	for(int i = 1 ; i <= N ; i++) {
		cin >> a[i];
	}
}
void solve (){
	for(int i = 1; i <= N ; i++) {
		for(int j = 1 ; j <= C ; j++) {
			if( j >= a[i]) {
				f[i][j] = max ( f[i-1][j], f[i-1][j-a[i]] + a[i]);
			}
			else f[i][j] = f[i-1][j];
		}
	}
	cout << f[N][C];
}
int main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	iNit();
	solve();

}






 
