#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, x, r[100005];
	cin>>t;
	while( t-- ){
		cin>>n;
		stack <int> val, pos;
		for(int i=1; i<=n; i++){
			r[i] = -1;
			cin>>x;
			while( !val.empty() && x > val.top() ){
				r[pos.top()] = x;
				val.pop();
				pos.pop();
			}
			val.push(x);	// value
			pos.push(i);	// position
		}
		for(int i=1; i<=n; i++){
			cout<<r[i]<<" ";
		}
		cout<<endl;
	}
}
