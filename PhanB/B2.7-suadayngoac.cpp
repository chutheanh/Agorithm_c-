#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	stack <char> st;
	int t, res = 0, tmp = 0;
	string s;
	cin>>t;
	while( t-- ){
		s = "";
		res = tmp = 0;
		cin>>s;
		for(int i=0; s[i]; i++){
			if( s[i] == '(' ) st.push(s[i]);
			else{
				if( !st.empty() ) st.pop();	// xoa mo ngoac
				else res++;	// het mo ngoac
			}
		}
		res -= res / 2;
		while( !st.empty() ){
			tmp++;
			st.pop();
		}
		res += tmp - ( tmp / 2 );
		cout<<res<<endl;
	}
}
