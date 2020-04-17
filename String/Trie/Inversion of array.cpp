//https://practice.geeksforgeeks.org/problems/inversion-of-array/0/?track=md-arrays&batchId=144
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

struct Node {
    int count;
    Node *left;
    Node *right;
};

Node *makeNewNode()
{
    Node* temp = new Node;
    temp -> count = 1;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

void insertElement(int num, Node* root, int &ans)
{
    for(int i=63; i>=0; i--)
    {
        int a = (num&(1<<i));
        if(a != 0)
        {
            if(root -> left != NULL)
                ans += root -> left -> count;
            
            if(root -> right != NULL)
            {
                root = root -> right;
                root -> count += 1;
            }
            else
            {
                root -> right = makeNewNode();
                root = root -> right;
            }
        }
        else
        {
            if(root -> left != NULL)
            {
                root = root -> left;
                root -> count += 1;
            }
            else
            {
                root -> left = makeNewNode();
                root = root -> left;
            }
        }
    }
}

int getInvCount(int a[], int n)
{
    Node *head = makeNewNode();
    int ans = 0;
    for(int i = n-1; i >= 0; i--)
        insertElement(a[i], head, ans);

    return ans;
}

signed main()
{
    FastIO;
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        int a[n+5];
        for(int i=0; i<n; i++)
            cin>>a[i];

        cout<<getInvCount(a, n)<<"\n";
    }
}