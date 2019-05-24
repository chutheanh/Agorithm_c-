#include <iostream>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	int n, a, b, res = 0;
	ii x[1000];
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a>>b;
		x[i] = ii(a, b);
	}
	sort(x, x+n);
	for(int i=0; i<n; i++){
		if( res < x[i].first ) res = x[i].first + x[i].second;
		else res += x[i].second;
	}
	cout<<res;
}

