#include<stdio.h>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int main(){
	string a,b;
	cin>>a>>b;
	string c="";
	string d="";
	string e="";
	string f="";
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='6') a[i]='5';
		c+=a[i];
	}
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='5') a[i]='6';
		d+=a[i];
	}
	for(int i=0;i<b.size();i++)
	{
		if(b[i]=='6') b[i]='5';
		e+=b[i];
	}
	for(int i=0;i<b.size();i++)
	{
		if(b[i]=='5') b[i]='6';
		f+=b[i];
	}
	int k=a.size()-1,k1=b.size()-1;
	int min1=0,min2=0,max1=0,max2=0;
	int mumin1=k;int mumax1=k;
	int mumin2=k1,mumax2=k1;
	for(int i=0;i<c.size();i++)
	{
		min1+=(c[i]-'0')*pow(10,mumin1);
		mumin1--;
	}
	for(int i=0;i<d.size();i++)
	{
		max1+=(d[i]-'0')*pow(10,mumax1);
		mumax1--;
	}
	for(int i=0;i<e.size();i++)
	{
		min2+=(e[i]-'0')*pow(10,mumin2);
		mumin2--;
	}
	for(int i=0;i<f.size();i++)
	{
		max1+=(f[i]-'0')*pow(10,mumax2);
		mumax2--;
	}
	cout<<min1+min2<<" "<<max1+max2;
}
 
