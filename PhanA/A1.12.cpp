#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdio.h>
 
using namespace std;
 
const int size = 100;
int maxE = 100;
int maxC = size * maxE;
 
int C[size][size];
int X[size+1];
int T[size];
 
int BestWay[size+1];
 
bool FREE[size];
 
int minSpending;
int M,N;
 
 
void Enter ()
{  
        int i,j,k;
        cout << " CITY: " ;         cin >> N;
        cout << " TRAFFIC ROAD: ";  cin >> M;
       
        for ( i = 0; i < N; i++ )
        {
                for ( j = 0; j < N; j++ )
                {
                        if ( i == j ) C[i][j] = 0;
                        else          C[i][j] = maxC;
       
                }
        }
        for ( int k = 0; k < M; k++ )
        {
                cout << "Enter i: "; cin >> i;
                cout << "Enter j: "; cin >> j;
                cout << "Cost : ";   cin >> C[i][j];
                C[j][i] = C[i][j];    
        }
}
void InI()
{
        for ( int i = 0; i <= N; i++ )
        {
                FREE[i] = true;
        }
 
        FREE[1] = false;
        X[0] = 1;
        T[0] = 0;
       
        minSpending = maxC;
}
 
void PRINT()
{
           if ( minSpending == maxC )
           {
                    cout << "NO SOLUTION ";
           }
           else
           {
                    for ( int i = 0; i < N; i++ )
                    {
                           cout << BestWay[i] << "->";
                    }
                    cout << " Minimum Spending is : " << minSpending;
           }
}
 
void BACKTRACK ( int i )
{
        for ( int j = 2; j <= N; j++ )
        {
                if ( FREE[j] == true )
                {
                        X[i] = j;
                        T[i] = T[i-1] + C[X[i-1]][j];
                        if ( T[i] < minSpending )
                        {
                                  if ( i < N )
                                  {
                                           FREE[j] = false;
                                           BACKTRACK ( i + 1 );
                                           FREE[j] = true;
                                  }
                        }
                        else
                        {
                                  if ( ( T[N] + C[X[N]][0] ) < minSpending )
                                  {
                                           for ( int var = 0; var <= N; var++ )
                                           {
                                                    BestWay[var] = X[var];
                                           }
                                           minSpending = T[N] + C[X[N]][0];
                                  }
                        }
               }
       }
}
 
int main()
{
          Enter();
          InI();
          BACKTRACK (1);
          PRINT();
          getch();
}
