#include <bits/stdc++.h>
using namespace std;
int M = 1e9+7;
long long F[101][50001];
main(){
    int t,n,k,i,j,x;
    cin >> t;
    while (t--){
        cin >> n >> k;
        if (k == 0 && n == 1) cout << 0 << endl;
        else{
        	memset(F, 0, sizeof(F));
        	for (i = 1; i <= 9; i++) 
				F[1][i] = 1;
	        for (i = 2; i <= n; i++)
	            for (j = 0; j <= k; j++)
	                for (x = 0; x <= 9; x++)
	                    if (j-x >= 0)
	                        F[i][j] = (F[i][j] + F[i-1][j-x])%M;
	        cout << F[n][k] << endl;
		}
    }
}

