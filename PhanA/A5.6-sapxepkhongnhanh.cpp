#include <iostream>
using namespace std;

void Copy(long long src[], int start, long long des[], int size){
	for(int i=0; i<size; i++) des[i] = src[start+i];
}

void process(long long a[], int n, long long b[], int m, long long arr[], int left){
	int i = 0, j = 0, k = left;	// i: chay tren a[], j: chay tren b[], k: chay tren arr[] tu left -> right
	while( i < n && j < m ){	// ket thuc vong lap se co 1 day da duyet het
		if( a[i] < b[j] ) arr[k++] = a[i++];
		else arr[k++] = b[j++];
	}
	while( i < n ) arr[k++] = a[i++];
	while( j < m ) arr[k++] = b[j++];
}

void merger(long long arr[], int left, int mid, int right){
	int n = mid - left + 1, m = right - mid;
	long long a[n+5], b[m+5];
	Copy(arr, left, a, n);
	Copy(arr, mid+1, b, m);
	process(a, n, b, m, arr, left);
}

void merge_sort(long long arr[], int left, int right){
	if( left < right ){
		int mid = ( right + left ) / 2;
		merge_sort(arr, left, mid);		// chia
		merge_sort(arr, mid+1, right);	// chia
		merger(arr, left, mid, right);	// tri
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, a[100005];
	cin>>n;
	for(int i=0; i<n; i++) cin>>a[i];
	merge_sort(a, 0, n-1);
	for(int i=0; i<n; i++) cout<<a[i]<<" ";
}
