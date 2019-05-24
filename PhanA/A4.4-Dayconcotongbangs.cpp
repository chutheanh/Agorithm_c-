#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n, k , a[205], Sum[40005];
int main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for( int i = 1 ; i <= n ; i++) {
		cin >> a[i];
		Sum[a[i]] = 1;
	}
	for(int i = 1; i <= n ; i++) {
		for(int j = k ; j >= a[i]; j--) {
			if( Sum[j-a[i]] == 1) Sum[j] = 1; 	
		}
	}
	if(Sum[k]) cout << "YES";
	else cout << "NO";

}






