#include <bits/stdc++.h>
using namespace std;

int *constructST(int a[],int n){
    int *tree = new int[n<<1];
    for(int i=0; i<n; i++) tree[n+i] = a[i];
    for(int i=n-1; i>=0; i--) tree[i] = min(tree[(i<<1)], tree[(i<<1)+1]);
    return tree;
}

int query(int *t, int n, int l, int r) {
    int minimum = INT_MAX;
    for(l+=n, r+=n; l < r; l=l>>1, r=r>>1)
    {
        if(l & 1) minimum = min(minimum, t[l++]);
        if(r & 1) minimum = min(minimum, t[--r]);
    }
    return minimum;
}

int RMQ(int st[] , int n, int l, int r){
    return query(st, n, l, r+1);
}

int main()
{
    int T,n;
    cin>>n;
    int l,r;
    int a[n+5];
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    int *st = constructST(a, n);
    
    cin>>T;
    while(T--)
    {
        cin>>l>>r;
    
        cout<<RMQ(st, n, l, r)<<"\n";
        
        for(int i=0; i<10; i++)
            cout<<st[i]<<" ";
    }
}