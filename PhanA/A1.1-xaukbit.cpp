#include<iostream>
using namespace std;
int t,n,k,ok=1,a[100],i,j;
void Init(){
	ok=1;
	cin >> n >> k;
	for(i=1; i<=n; i++){
		a[i]=0;
	} 
}
void Result(){
	for(i=1; i<=n; i++){
		cout << a[i];
	}
	cout << endl;
}
int Check(){
	int Sum=0;
	for(i=1; i<=n; i++){
		if(a[i]) Sum++;
	}
	if(Sum==k) return 1;
	return 0;
}
void Next(){
	i=n;
	while(i>0 && a[i]==1){
		a[i]=0;
		i--;
	}
	if(i>0) a[i]=1; 
	else{
		ok=0;
	}	
}
main(){
	cin >> t;
	while(t--){
		Init();
		while(ok){ 
			if(Check()) Result();
			Next();
		}
	}
	return 0;
}
