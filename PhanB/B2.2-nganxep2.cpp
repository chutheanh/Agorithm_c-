#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	stack <int> st;
	int q, x;
	string s;
	cin>>q;
	while( q-- ){
		cin>>s;
		if( s == "PUSH" ){
			cin>>x;
			st.push(x);
		}
		else if( s == "POP" ){
			if( !st.empty() ) st.pop();
		}
		else{
			if( st.empty() ) cout<<"NONE\n";
			else cout<<st.top()<<endl;
		}
	}
}
