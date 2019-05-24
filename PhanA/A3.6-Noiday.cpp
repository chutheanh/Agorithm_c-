#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int NMAX = 1e6, base = 1e9+7;
int n , c[2*NMAX+5];
void init() {
	cin >> n;
	for(int i = 1 ; i <= n ; i++) 
		cin >> c[i];
}

int main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	priority_queue <int,vector<int>,greater<int> > p_q;
	init();
	sort(c+1,c+n+1);
	for(int i = 1 ; i <= n ; i++)
		p_q.push(c[i]);
	ll ans = 0;
	for(int i = 1  ; i <n; i++) {
		int a = p_q.top();
		p_q.pop();
		int b = p_q.top();
		p_q.pop();
		ans += (a+b);
		ans %= base;
		p_q.push((a+b)%base);
		//cout << a << " " << b << endl;
	}
	cout << ans;
}






