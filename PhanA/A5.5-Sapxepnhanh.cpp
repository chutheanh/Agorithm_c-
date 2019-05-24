#include <iostream>
using namespace std;

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int pivot(int arr[], int left, int right){
	int tmp = arr[left], i = right + 1;	// i: luu vi tri cua pivot
	for(int j=right; j>left; j--){	// dua cac so > pivot ve ben phai
		if( tmp < arr[j] ) swap(arr+--i, arr+j);	// vi i giam cham hon j nen phep doi cho luon dua cac so > tmp ve ben phai
	}
	swap(arr+--i, arr+left);
	return i;
}

void quick_sort(int arr[], int left, int right){
	if( left < right ){
		int p = pivot(arr, left, right);	// tim chot va tri
		quick_sort(arr, left, p-1);		// chia
		quick_sort(arr, p+1, right);	// chia
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, a[100005];
	cin>>t;
	while( t-- ){
		cin>>n;
		for(int i=0; i<n; i++) cin>>a[i];
		quick_sort(a, 0, n-1);
		for(int i=0; i<n; i++) cout<<a[i]<<" ";
		cout<<endl;
	}
}
