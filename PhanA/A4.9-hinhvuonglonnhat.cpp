#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1000001], M[1001][1001], S[1001][1001];
void xuly(){
  int max=0,i,j;
  for(i = 0; i < n; i++) S[i][0] = M[i][0];
  for(j = 0; j < m; j++) S[0][j] = M[0][j];
  for(i = 1; i < n; i++) 
    for(j = 1; j < m; j++)
      if(M[i][j] == 1) 
	  	  S[i][j] = min(S[i][j-1], min(S[i-1][j], S[i-1][j-1])) + 1;
      else S[i][j] = 0;
  for(i = 0; i < n; i++)
    for(j = 0; j < m; j++)
      if(max < S[i][j])
        max = S[i][j];
    cout << max << endl;
}
main(){
    int t,i,j;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				cin >> M[i][j];
        xuly();
    }
}
