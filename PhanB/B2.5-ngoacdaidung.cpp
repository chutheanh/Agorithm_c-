#include <iostream>
#include <stack>
using namespace std;

int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
	int t, close, max, tmp;
	string s;
	stack <int> st, vt;		// st: luu ngoac, vt: luu vi tri sai
	cin>>t;
	while( t-- ){
		cin>>s;
		close = s.size(); 
		max = 0;
		for(int i=0; s[i]; i++){
			if( s[i] == '(' ){
				st.push(0);
				vt.push(i);	// vi tri mo ngoac
			}
			else{	// dau dong ngoac
				if( !st.empty() ){	// dong ngoac dung
					st.pop();
					vt.pop();
				}
				else{	// dong ngoac sai
					vt.push(i);		// vi tri 
				}
			}
		}
		while( !st.empty() ) st.pop();
		while( !vt.empty() ){
			tmp = close - vt.top() - 1;		// so luong dau ngoac dung lien tiep
			close = vt.top();
			vt.pop();
			if( tmp > max ) max = tmp;
		}
		tmp = close - (-1) - 1;
		if( tmp > max ) max = tmp;
		cout<<max<<endl;
	}
}
