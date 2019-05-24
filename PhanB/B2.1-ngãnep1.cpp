#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	stack <int> st, tmp;
	int x;
	string s;
	while( cin>>s ){
 		if( s == "push" ){
 			cin>>x;
 			st.push(x);
		}
		else if( s == "pop" ){
			if( !st.empty() ) st.pop();
		}
		else{
			bool check = 1;
			while( !st.empty() ){
				if( check ) check = 0;
				tmp.push( st.top() );
				st.pop();
			}
			if( check ) cout<<"empty\n";
			else{
				while( !tmp.empty() ){
					st.push( tmp.top() );
					tmp.pop();
					cout<<st.top()<<" ";
				}
				cout<<endl;
			}
		}
	}
}
