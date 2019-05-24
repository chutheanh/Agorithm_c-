#include<stdio.h>

class abc
{
public:
int n;
int min;
int d[15],x[15];
int A[15][15];
void read();
void TRY(int k,int M);
};
void abc::TRY(int k,int M)
{
if(k==n) {min=M;return;}
for(int t=1;t<=n;t++)
if(d[t]==0 && M+A[x[k]][t]<min)
{
x[k+1]=t;
d[t]=1;
TRY(k+1,M+A[x[k]][t]);
d[t]=0;
}
}
int dem(char *s,char *t)
{
char D[200];
for(char c='A';c<='Z';c++) D[c]=0;
for(char *p=s;*p;p++) D[*p]++;
int k=0;
for(char *p=t;*p;p++) if(D[*p]) k++;
return k;
}

void abc::read()
{
char x[15][30];
scanf("%d",&n);
for(int i=1;i<=n;i++) {scanf("%s",x[i]);d[i]=0;A[i][0]=A[0][i]=0;}
for(int i=1;i<=n;i++)
for(int j=i+1;j<=n;j++)
{
A[i][j]=A[j][i]=dem(x[i],x[j]);
}
min=300;
}

int main()
{
abc A;
A.read();
A.TRY(0,0);
printf("%d",A.min);
}
