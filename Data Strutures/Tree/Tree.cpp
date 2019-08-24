#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root = NULL;

void preOrder(struct node *root)
{
	if(root != NULL)
	{
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(struct node *root)
{
	if(root != NULL)
	{
		preOrder(root->left);
		cout<<root->data<<" ";
		preOrder(root->right);
	}
}

void postOrder(struct node *root)
{
	if(root != NULL)
	{
		preOrder(root->left);
		preOrder(root->right);
		cout<<root->data<<" ";
	}
}

struct node* newNode(int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = data;
	temp -> left = NULL;
	temp -> right = NULL;

	return temp;
}

signed main()
{
    root = newNode(10);
    root -> left = newNode(20);
    root -> right = newNode(30);
    
    root -> left -> left = newNode(40);
    root -> left -> right = newNode(50);

	preOrder(root);
	cout<<"\n";
	postOrder(root);
	cout<<"\n";
	inOrder(root);
}