#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
void solve() {
	int tmp = n/7, kt = 1, i;
	for( i = tmp ; i >= 0 ; i--) {
		if( (n-i*7) % 4 == 0) {
			kt = 0;
			break;
		}
	}
	if(kt) cout << "-1" << endl;
	else {
		if(i == 0) for(int i = 1 ; i <= n/4 ; i++) cout << "4";
		else {
			int tmp = (n-i*7) / 4;
			for(int j = 1 ; j <= tmp ; j++) cout << "4";
			for(int j = 1 ; j <= i ; j++) cout << "7";
		}
	}
	cout << endl;
}
int main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	while(test--) {
		cin >> n;
		solve();
	}


}






