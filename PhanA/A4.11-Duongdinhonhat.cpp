#include<iostream>
using namespace std;
main(){
	int m,n,F[501][501],t,a,i,j;
    cin>>t;
    while(t--){
    	cin>>n>>m;
    	for(i=1;i<=n;i++){
    		for(j=1;j<=m;j++){
    			cin>>a;
    			if(i==1&&j==1) F[i][j]=a;
    			else if(i==1) F[i][j]=F[i][j-1]+a;
    			else if(j==1) F[i][j]=F[i-1][j]+a;
    			else F[i][j] = min(F[i][j-1],min(F[i-1][j-1],F[i-1][j]))+a;
			}
		}
		cout<<F[n][m]<<endl;
	}
	return 0;
}

