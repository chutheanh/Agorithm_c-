#include <iostream>
#include <cstring>
using namespace std;

void fix(string &a){
	for(int i=0; a[i]; i++) a[i] = tolower(a[i]);
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	int t;
	cin>>t;
	string a, b;
	while( t-- ){
		cin>>a>>b;
		int key = 0;	// vi tri duyet tren xau b
		fix(a);
		fix(b);
		for(int i=0; i<a.size(); i++){
			if( a[i] == b[key] ) key++;
			else{
				key = 0;
				i--;
			}
			if( key == b.size() ) break;
		}
		if( key == b.size() ) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
