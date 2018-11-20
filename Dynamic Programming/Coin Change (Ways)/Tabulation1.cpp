#include<bits/stdc++.h> 
using namespace std; 

int count( int coin[], int m, int n ) 
{ 
    int table[n+1]; 
    memset(table, 0, sizeof(table)); 
    table[0] = 1; 

    for(int i=0; i<m; i++) 
        for(int j=coin[i]; j<=n; j++) 
            table[j] += table[j-coin[i]]; 
  
    return table[n]; 
}
  
int main() 
{ 
    int coin[] = {1, 2, 3}; 
    int m = sizeof(coin)/sizeof(coin[0]); 
    int n = 4; 
    cout << count(coin, m, n); 
    return 0; 
} 