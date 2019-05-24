#include <iostream>
using namespace std;
void xuly(string s){
	int kq = 0,n =s.length(),i,j,m,d;
	for(i = 0 ; i < n ; i++){
		m = min(i+1,n-i);
		d = 1; 
		if(s[i] != s[i+1])
			for(j = 1 ; j < m ;j++) 
				if(s[i - j] == s[i+j] ) 
					d+=2;
				else break;
		else{
			m = min(i+1,n-i-1);
			d++;
			for(j = 1 ; j < m ;j++) 
				if(s[i - j] == s[i+j+1] ) 
					d+=2;
				else break;
		}
		if(d > kq ) kq = d; 
	}
	cout << kq <<endl;
}
main(){
	string s; int t;
	cin >> t;
	while(t--){
		cin >> s;
		xuly(s);
	}
}


