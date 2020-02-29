//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/tutorial/
#include <bits/stdc++.h>
#define Max 10000000
#define int long long int
using namespace std;

int min(int x, int y) { return (x < y)? x: y; }

void update(int ST[], int l, int r, int si, int i, int diff)
{
    if (i < l || r < i)
        return;

    if(l==r)
        ST[si] = diff;
    else
    {
        int mid=(l+r)/2;
        update(ST, l, mid, 2*si+1, i, diff);
        update(ST, mid+1, r, 2*si+2, i, diff);
        ST[si]=min(ST[2*si+1], ST[2*si+2]);
    }
}

int query(int ST[], int s, int e, int l, int r, int i)
{
//  cout<<l <<" "<<r<<endl;
    if(r<s || e<l)
        return Max;

    if(s<=l && r<=e)
        return ST[i];

    int mid=(l+r)/2;
    return min(query(ST, s, e, l, mid, 2*i+1), query(ST, s, e, mid+1, r, 2*i+2));
}


int build(int ST[], int A[], int l, int r, int i)
{
    if(l==r)
    {
        ST[i] = A[l];
        return ST[i];
    }

    int mid = (l+r)/2;
    build(ST, A, l, mid, 2*i+1);
    build(ST, A, mid+1, r, 2*i+2);
    ST[i] = min(ST[2*i+1], ST[2*i+2]);
}

signed main()
{
    char o;
    int i,N,Q,s,e,n,j,x,diff;
    cin>>N>>Q;
    int A[100005],ST[400005];

    for(i=0; i<N; i++){
        cin>>A[i];
    //    A[i]=i+1;
    }

    build(ST, A, 0, N-1, 0);
//  for(i=0; i<15; i++)
//        cout<<ST[i]<<" ";
//    cout<<endl;

    for(i=0; i<Q; i++)
    {
//      o=getchar();
        scanf(" %c", &o);
        if(o=='q')
        {
            cin>>s>>e;
            diff=query(ST, s-1, e-1, 0, N-1, 0);
            cout<<diff<<endl;
        }
        else
        {
            cin>>j>>x;
            A[j-1]=x;
            update(ST, 0, N-1, 0, j-1, x);
/*          for(int a=0; a<2*N; a++)
                cout<<ST[a]<<" ";
            cout<<endl;*/
        }
    }
}
