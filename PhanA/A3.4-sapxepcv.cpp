#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int NMAX = 1e5;
int test, n; 
struct CV {
	int begin;
	int end;
}typedef CV;
bool cmp( CV a, CV b) {
	return (a.end < b.end);
}
CV a[NMAX + 5];
int solve() {
	int x = a[1].end , ans =1;
	for (int i=2; i<=n; i++)	{
		if (x<=a[i].begin) {
			ans++;
			x=a[i].end;
		}
	}
	return ans;
}
int main()
{
// 	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
	cin >> test;
	while(test--) {
		cin >> n;
		for(int i = 1 ; i <= n ; i++) {
			cin >> a[i].begin >> a[i].end;
		}
		sort(a+1, a+n+1, cmp);
		cout << solve() << endl;
	}


}






