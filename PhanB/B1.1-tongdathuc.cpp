#include <iostream>
#include <cstring>
using namespace std;

void process(string s, int res[]){
	getline(cin, s);
	bool flag = 0, c1 = 0, c2 = 0;	// flag = 0: dang o khoang trang
	int heso, mu, len = s.size();
	for(int i=0; i<len; i++){
		if( flag == 0 && s[i] != ' ' && s[i] != '+' ){	// bat dau vao 1 hang tu moi
			flag = 1;
			c1 = 1;	// heso
			c2 = 0;	// mu
			heso = mu = 0;	// reset moi khi gap 1 hang tu
		}
		else if( flag == 1 && ( s[i] == ' ' || i == len-1 ) ){	// gap khoang trang hoac la phan tu cuoi cung thi ket thuc hang tu dang xet
			res[mu] += heso;	// update
			flag = 0;
		}
		if( flag ){	// duyet trong 1 hang tu
			if( s[i] == '*' ) c1 = 0;	// ket thuc he so
			if( c1 ){	// gap he so
				heso = heso * 10 + ( s[i] - '0' );
			}
			if( c2 ){	// gap so mu
				mu = mu * 10 + ( s[i] - '0' );
			}
			if( s[i] == '^' ) c2 = 1;	// bat dau so mu
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, hs[10005] = {0};
	string s, res = "";
	cin>>t;
	cin.ignore();
	while( t-- ){
		memset(hs, 0, sizeof(hs));	// reset
		process(s, hs);
		process(s, hs);
		bool first = 1;
		for(int i=1e4; i>=0; i--){
			if( hs[i] ){
				if( first ) first = 0;
				else cout<<" + ";
				cout<<hs[i]<<"*x^"<<i;
			}
		}
		cout<<endl;
	}
}
