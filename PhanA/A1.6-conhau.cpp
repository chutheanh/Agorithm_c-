#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int a[10],n;
int dem =0;
bool Ok(int x2,int y2){
    for(int i = 1; i < x2 ;i++)
        if(a[i] == y2 || abs(i-x2) == abs(a[i] - y2) )
            return false;
    return true;
}
 
void Try(int i,int n){
    for(int j = 1;j<=n;j++){
        if(Ok(i,j)){
            a[i] = j;
            if(i==n) dem++;
            Try(i+1,n);
        }
    }  
}
 
int main(){
    cin>>n;
    if(0<n<10){
    	  Try(1,n);
    cout<<dem;
	}
  
    return 0;
}
