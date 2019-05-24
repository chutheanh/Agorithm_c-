#include <iostream>
#include <queue>
using namespace std;

long long res[600];

void process(){
	queue <long long> q;
	q.push(9);
	long long tmp, t;
	int d[505] = {0};
	while( 1 ){
		tmp = q.front();
		q.pop();
		int dem = 0;
		for(int i=1; i<=500; i++){
			if( d[i] == 0 && tmp % i == 0 ){
				d[i] = 1;
				res[i] = tmp;
			}
			if( d[i] == 1 ) dem++;
		}
		if( dem == 500 ) break;
		t = tmp * 10;
		q.push(t);
		t += 9;
		q.push(t);
	}
}

int main()
{
	int t, n;
	cin>>t;
	process();
	while( t-- ){
		cin>>n;
		cout<<res[n]<<endl;
	}
}
