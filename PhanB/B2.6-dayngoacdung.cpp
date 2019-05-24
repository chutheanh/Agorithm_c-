#include <iostream>
#include <stack>
using namespace std;

int change(char x){
	if( x == '(' || x == ')' ) return 0;
	else if( x == '[' || x == ']' ) return 1;
	return 2;
}

bool check(string s){
	stack <char> st;
	for(int i=0; s[i]; i++){
		if( s[i] == '(' || s[i] == '{' || s[i] == '[' ) st.push(s[i]);
		else{	// gap dau dong ngoac
			if( !st.empty() && change(s[i]) == change(st.top()) ){
				st.pop();
			}
			else return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	string s;
	cin>>t;
	while( t-- ){
		s = "";
		cin>>s;
		if( s == "" || check(s) ) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
