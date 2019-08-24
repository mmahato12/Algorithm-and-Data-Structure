#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

struct node {
	int data;
	struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void print()
{
	struct node *ptr = head;
	while(ptr != NULL)
	{
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<"\n";
}

void insertFirst(int data)
{
	struct node *temp = (struct node*)malloc(sizeof(node));
	temp ->data = data;
	temp ->next = head;
	head = temp; 
}

void insertLast(int data)
{
	struct node *temp = (struct node*)malloc(sizeof(node));
	struct node *ptr = head;
	
	while(ptr->next != NULL)
		ptr = ptr->next;

	temp ->data = data;
	temp ->next = NULL;
	ptr ->next = temp;
}

void deleteFirst()
{
	struct node *ptr = head;
	int data = ptr->data;
	if(ptr != NULL)
	{
		head = head->next;
		ptr ->next = NULL;
		delete(ptr);
	}
	
	cout<<"Element Deleted : "<<data<<"\n";
}

void deleteLast()
{
	struct node *ptr1 = head;
	struct node *ptr2 = head;
	while(ptr2 != NULL)
	{
		ptr1 = ptr2;
		ptr2 = ptr2 ->next;
	}
	cout<<"Element Deleted : "<<ptr2->data<<"\n";
	ptr1 ->next = NULL;
	delete(ptr2);
}

void ReverseList()
{
	struct node *curr = head;
	struct node *prev = NULL;
	while(head != NULL)
	{
		head = head -> next;
		curr -> next = prev;
		prev = curr;
		curr = head;
	}

	head = prev;
}

signed main()
{
	insertFirst(40);
	insertFirst(30);
	insertFirst(20);
	insertFirst(10);

	insertLast(50);

	deleteFirst();
    deleteLast();
    
	print();
	ReverseList();
	print();
}