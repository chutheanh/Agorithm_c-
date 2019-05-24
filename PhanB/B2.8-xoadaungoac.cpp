#include<iostream>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;

struct cap{
	int x;
	int y;
};
stack <int> stark;	//luu cac cap ngoac
vector <string> vt;	//luu cac chuoi ket qua de sort

cap cow[20];
int cs=0, a[20], kt=0;	//cs: so cap ngoac, a[]: luu so nhi phan, kt=0: de tranh cau hinh full 0
string s;

void B1(){	//buoc 1: luu vi tri cac cap ngoac vao stack	//OK
	for(int i=0; s[i]; i++){
		if( s[i]=='(' ){
			stark.push(i);	//them vi tri cua mo ngoac vao stack
		}
		if( s[i]==')' ){
			cow[cs].x = stark.top();	//luu vi tri mo ngoac
			cow[cs++].y = i;	//luu vi tri dong ngoac
			stark.pop();	//xoa phan tu tren cung trong stack
		}
	}
}

void B2(int i){	//buoc 2: sinh nhi phan de danh dau cap ngoac bi xoa	//OK
	for(int j=0; j<2; j++){
		a[i] = j;	//luu bit nhi phan
		if( i==cs-1 ){	//xay dung duoc 1 cau hinh nhi phan
			if( kt==1 ){
				int dd[250]={0};	//mang danh dau vi tri xoa
				for(int k=0; k<=i; k++){	//danh dau cac vi tri can xoa
					if( a[k]==1 ){	//bit 1
						dd[ cow[k].x ] = 1;
						dd[ cow[k].y ] = 1;
					}
				}
				string tam = "";
				for(int k=0; s[k]; k++){
					if( dd[k]==0 ) tam += s[k];	//tao chuoi da xoa dau ngoac
				}
				vt.push_back(tam);	//them chuoi tam vao vecto vt
			}
			if( kt==0 ) kt=1;
		}
		if( i<cs-1 ) B2(i+1);
	}
}

void B3(){	//buoc 3: xep theo tu dien + chi in cac chuoi khac nhau		//OK
	for(int i=0; i < vt.size(); i++){
		for(int j=i+1; j < vt.size(); j++){
			if( vt[i] > vt[j] ){
				vt[i].swap( vt[j] );	//doi 2 chuoi
			}
		}
	}
	int dd=0;	//danh dau moc so sanh
	for(int i=0; i<vt.size(); i++){
		if( i>0 ){
			if( vt[i] != vt[dd] ){
				cout<<vt[i]<<endl;
				dd = i;
			}
		}
		else cout<<vt[i]<<endl;
	}
}

int main()
{
	cin >> s;
	B1();
	B2(0);
	B3();
	return 0;
}
