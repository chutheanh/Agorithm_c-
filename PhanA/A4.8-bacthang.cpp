#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int base = 1E9 + 7;
int t, n , k;
ll f[100005], a[105]; 
int main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	for(int i = 1 ; i <= 105 ; i++)
		a[i] = i;
	f[0] = 1;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		for(int i = 1 ; i <= k ; i++) {
			for(int j = a[i] ; j <= n ; j++) {
				f[j] = ( f[j] + f[j-a[i]]);
				f[j] %= base;
			}
		}
		cout << f[n] << endl;
	} 

}






