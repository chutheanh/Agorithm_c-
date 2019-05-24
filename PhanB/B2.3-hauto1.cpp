#include <iostream>
#include <stack>
using namespace std;

int change(char x){
	if( x == '(' || x == ')' ) return 0;
	if( x == '+' || x == '-' ) return 1;
	return 2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	stack <char> st;
	string s, res;
	int q;
	cin>>q;
	while( q-- ){
		s = res = "";
		cin>>s;
		for(int i=0; s[i]; i++){
			if( s[i] >= 'a' ) res += s[i];
			else{
				if( s[i] == '(' || st.empty() || change(s[i]) > change(st.top()) ){
					st.push(s[i]);
				}
				else{	// dau nho hon hoac dong ngoac
					while( !st.empty() && change(s[i]) <= change(st.top()) ){
						if( st.top() == '(' ){
							st.pop();	// gap mo ngoac
							break;
						}
						res += st.top();
						st.pop();
					}
					if( change(s[i]) ) st.push(s[i]);	// khong phai dong ngoac
				}
			}
		}
		while( !st.empty() ){	// lay not 1 dau con sot trong stack neu co
			res += st.top();
			st.pop();
		}
		cout<<res<<endl;
	}
}
