#include<iostream>
#include<stack>
#include<vector>
using namespace std;

stack <char> st;
vector <char> kq;
string s;

int check(char c){
	if( c=='+' || c=='-' ) return 1;
	if( c=='*' || c=='/' ) return 2;
	return 0;	//dau mo ngoac
}

void change(){	//chuyen trung to thanh hau to
	for(int i=0; s[i]; i++){
		if( s[i]>='0' && s[i]<='9' ){
			kq.push_back( s[i] );	//neu la so thi cho vao chuoi ki tu
		}
		if( s[i]=='(' ){
			st.push( s[i] );	//neu la mo ngoac push vao stack
		}
		if( s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' ){
			if( kq.back()!=' ' ) kq.push_back( ' ' );	//them khoang trang de tach cac so
			if( !st.empty() ){
				while( check( s[i] ) <= check( st.top() ) ){	//lay tat ca cac ky tu co do uu lien >= s[i] cho vao chuoi
					if( kq.back()!=' ' ) kq.push_back( ' ' );	//them khoang trang sau khi them phep tinh
					kq.push_back( st.top() );
					st.pop();
					if( st.empty() ) break;
				}
			}
			if( kq.back()!=' ' ) kq.push_back( ' ' );
			st.push( s[i] );
		}
		if(s[i]==')') {
			while( st.top()!='(' ){
				if( kq.back()!=' ' ) kq.push_back( ' ' );	//them khoang trang sau khi them phep tinh
				kq.push_back( st.top() );
				st.pop();
			}
			st.pop();	//xoa mo ngoac
		}
	}
	while( !st.empty() ){
		if( kq.back()!=' ' ) kq.push_back( ' ' );	//them khoang cach giua cac phep tinh
		kq.push_back( st.top() );
		st.pop();
	}
}

void solve(){	//tinh toan
	stack <long long> k;
	for(int i=0; i<kq.size(); i++){
		if( kq[i]>='0' && kq[i]<='9' ){
			long long tmp = 0;
			while( kq[i]>='0' && kq[i]<='9' ){	//chay den khi gap khoang trang
				tmp = tmp*10 + ( kq[i]-48 );
				i++;
			}
			k.push( tmp );
		}
		if( kq[i]=='+' || kq[i]=='-' || kq[i]=='*' || kq[i]=='/' ){
			long long op2 = k.top();
			k.pop();
			long long op1 = k.top(), tmp;
			k.pop();
			if( kq[i]=='+' ) tmp = op1 + op2;
			if( kq[i]=='-' ) tmp = op1 - op2;
			if( kq[i]=='*' ) tmp = op1 * op2;
			if( kq[i]=='/' ) tmp = op1 / op2;
			k.push( tmp );
		}
	}
	cout<<k.top()<<endl;
}

int main()
{
	long long test;
	cin>>test;
	cin.ignore();
	while( test-- ){
		getline(cin, s);
		change();
		solve();
		while( !kq.empty() ) kq.pop_back();	//reset chuoi
	}
}
