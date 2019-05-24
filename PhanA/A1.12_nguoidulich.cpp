#include<bits/stdc++.h>
using namespace std;
 
const int size = 20;
 
int maxE = 100;
int maxC = size * maxE;
int C[size][size];  //Ma tr?n chi ph�
int X[size+1];  //X d?th?c�c kh?nang, BestWay d?ghi nh?n nghi?m
int T[size];  //T[i] d?luu chi ph� di t?X[1] d?n X[i]
int BestWay[size+1];  //, BestWay d? ghi nh?n nghi?m
bool FREE[size];  //Free d? d�nh d?u, Free[i]= True n?u chua di qua tp i
int minSpending;  //Chi ph� h�nh tr�nh t?i uu
int M,N;
 
void input()
{
 
    int i,j,k;
    cin >> N;   //Nhap so thanh pho
    cin >> M;   //Nhap so duong
    for ( i = 1; i <= N; i++ )  //Kh?i t?o b?ng chi ph� ban d?u
    {
        for ( j = 1; j <= N; j++ )
        {
            if ( i == j ) C[i][j] = 0;
            else C[i][j] = maxC;
        }
    }
 
    for ( int k = 1; k <= M; k++ )
    {
        cin >> i;  //Nhap thanh pho bat dau
        cin >> j;  //Nhap thanh pho den
        cin >> C[i][j];  //Nhap gia di tu thanh pho i den j
        C[j][i] = C[i][j];  //Chi ph� nhu nhau tr�n 2 chi?u
    }
}
 
void init()
{
    for ( int i = 0; i <= N; i++ )
        FREE[i] = true;
    FREE[1] = false;  //C�c th�nh ph? l� chua di qua ngo?i tr? th�nh ph? 1
    X[1] = 1;  //xuat phat tu thanh pho 1
    T[1] = 0;  //Chi ph� t?i th�nh ph? xu?t ph�t l� 0
    minSpending = maxC;
}
 
void output()
{
    if ( minSpending == maxC )
        cout << "NO SOLUTION ";
    else
    {
        for ( int i = 1; i <= N; i++ )
            cout << BestWay[i] << "->";
        cout << "1" << endl;
        cout << "Cost : " << minSpending;
    }
}
 
void tim(int i)  //Th? c�c c�ch ch?n xi
{
    for ( int j = 2; j <= N; j++ )  //Th? c�c th�nh ph? t? 2 d?n n
    {
        if (FREE[j])   //N?u g?p th�nh ph? chua di qua
        {
            X[i] = j;
            T[i] = T[i-1] + C[X[i-1]][j];  //Chi ph� = Chi ph� bu?c tru?c + chi ph� du?ng di tr?c ti?p
            if ( T[i] < minSpending )   //Hi?n nhi�n n?u c� di?u n�y th� C[x[i - 1], j] < +8 r?i
            {
                FREE[j] = false;  //��nh d?u th�nh ph? v?a th?
                if(i == N)
                {
                    if ( ( T[N] + C[X[N]][1] ) < minSpending )  // T?x[n] quay l?i 1 v?n t?n chi ph� �t hon tru?c
                    {
                        for ( int i = 0; i <= N; i++ )  // C?p nh?t BestConfig
                            BestWay[i] = X[i];
                        minSpending = T[N] + C[X[N]][1];
                    }
                }
                else tim( i + 1 );  //  T�m c�c kh? nang ch?n x[i+1]
                FREE[j] = true;  // B? d�nh d?u
            }
        }
    }
}
 
int main()
{
    input();
    init();
    tim(2);
    output();
}
