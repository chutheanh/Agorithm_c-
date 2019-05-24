#include<bits/stdc++.h>
using namespace std;
int n,c,v[105],maxval,val=0;
void init( ){
	cin >> c >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> v[i];
	}
}
void Try(int i){
	for(int j = i + 1 ; j <= n ; j++){
		val += v[j];
		if(val <= c){
			maxval = max(val , maxval);
			Try(j);
		}
		val -= v[j];
	}
	
}
int main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	init();
	Try(0);
	cout << maxval;
 
}
 
 
