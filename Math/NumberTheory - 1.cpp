//https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/tutorial/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int d,x,y;
void extendedEuclid(int C, int M)
{
	if(M==0)
	{
		d = C;
		x = 1;
		y = 0;
	}
	else
	{
		extendedEuclid(M, C%M);
		int temp = x;
		x = y;
		y = temp - (C/M)*y;
	}
}

int modInverse(int C, int M)
{
    extendedEuclid(C, M);
    return (x%M + M)%M;
}

int FastExp(int A, int B, int M)
{
    int res=1;
    while(B)
    {
        if(B%2 == 1)
            res = (res*A)%M;
        A = (A*A)%M;
        B = B/2;
    }
    return res;
}

signed main()
{
    int A,B,C,M;
    cin>>A>>B>>C>>M;
    
    int num = FastExp(A%M, B%M, M);
    int deno = modInverse(C, M);
    int ans = (num*deno)%M;

    cout<<num<<" "<<deno<<"\n";
    cout<<ans;
}