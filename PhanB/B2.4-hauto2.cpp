#include <iostream>
#include <stack>
using namespace std;

int change(char x){
	if( x == '(' || x == ')' ) return 0;
	if( x == '+' || x == '-' ) return 1;
	if( x == '*' || x == '/' ) return 2;
	return 3;
}

string fix(string s){
	stack <int> vt;
	bool d[60] = {0};	// danh dau vi tri ngoac sai
	string res = "";
	for(int i=0; s[i]; i++){
		if( s[i] == '(' ) vt.push(i);	// vi tri mo ngoac
		else if( s[i] == ')' ){
			if( !vt.empty() ) vt.pop();	// co dau mo ngoac tuong ung
			else d[i] = 1;	// dong ngoac sai
		}
	}
	while( !vt.empty() ){
		d[ vt.top() ] = 1;
		vt.pop();
	}
	for(int i=0; s[i]; i++){
		if( !d[i] ) res += s[i];
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	stack <char> st;
	int t;
	string s, res;
	cin>>t;
	while( t-- ){
		s = res = "";
		cin>>s;
		s = fix(s);
		for(int i=0; s[i]; i++){
			if( s[i] >= 'a' ) res += s[i];
			else if( s[i] == '(' ) st.push(s[i]);	// luon push mo ngoac
			else{	// phep tinh hoac dong ngoac
				if( st.empty() || change(s[i]) > change(st.top()) ){
					st.push(s[i]);	// chi them dau trong so lon hon
				}
				else{
					while( !st.empty() && change(s[i]) <= change(st.top()) ){
						if( st.top() == '(' ){
							st.pop();	// gap mo ngoac
							break;
						}
						res += st.top();
						st.pop();
					}
					if( change(s[i]) ) st.push(s[i]);
				}
			}
		}
		while( !st.empty() ){	// lay not dau con sot trong stack neu co
			res += st.top();
			st.pop();
		}
		cout<<res<<endl;
	}
}
