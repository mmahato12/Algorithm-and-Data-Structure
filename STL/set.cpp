#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void Print1(set <int> s)
{
    for(auto &x: s)
        cout<<x<<" ";
    cout<<"\n";
}

void Print2(set <int, greater <int> > s)
{
    for(auto &x: s)
        cout<<x<<" ";
    cout<<"\n";
}

void Insert(set <int> &s1, set <int, greater <int> > s2)
{
    for(auto &x: s2)
        s1.insert(x);
}

signed main()
{
    FastIO;
    int n;
    set <int> s1;       // set container (ascending order)
    s1.insert(9);
    s1.insert(3);
    s1.insert(8);
    s1.insert(4);
    s1.insert(3);       // only one 3 will be added to the set
    s1.insert(6);

    cout<<"ascending order : \n";
    set <int> :: iterator itr1;
    for(itr1 = s1.begin(); itr1 != s1.end(); itr1++)
        cout<<*itr1<<" ";
    cout<<"\n";
    
    cout<<"reverse iterator : \n";
    set <int> :: reverse_iterator itr3;
    for(itr3 = s1.rbegin(); itr3 != s1.rend(); itr3++)
        cout<<*itr3<<" ";
    cout<<"\n";
    
    set <int, greater <int> > s2(s1.begin(), s1.end());     // assigning (descending order)
    
    cout<<"descending order : \n";
    set <int, greater <int> > :: iterator itr2;
    for(itr2 = s2.begin(); itr2 != s2.end(); itr2++)
        cout<<*itr2<<" ";
    cout<<"\n";
    
    int num;
    num = s1.erase (6);             // Remove element form the set
    cout << "\ns1.erase(6) : ";
    cout << num << " removed \n\n" ;

    Insert(s1, s2);

    Print1(s1);
    //lower bound and upper bound for set s1
    cout << "s1.lower_bound(4) : " << *s1.lower_bound(4) << endl; 
    cout << "s1.upper_bound(4) : " << *s1.upper_bound(4) << endl; 
    
    Print2(s2);    
    //lower bound and upper bound for set s2 
    cout << "s2.lower_bound(4) : " << *s2.lower_bound(4) << endl; 
    cout << "s2.upper_bound(4) : " << *s2.upper_bound(4) << endl;
    cout<<"\n";
    
    if (s1.count(6)) 
        cout << "6 is present in the set\n"; 
    else
        cout << "6 is not present in the set\n";
        
    auto pos = s1.find(3);          // return address if element is present, otherwise end
    cout<<*pos<<"\n";

    s1.clear();                     // Clears the set
}