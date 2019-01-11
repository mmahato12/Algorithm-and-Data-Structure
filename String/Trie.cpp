//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/tutorial/
#include <bits/stdc++.h> 
using namespace std; 
const int ALPHABET_SIZE = 26; 

struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
    int wt;
    bool isEndOfWord; 
};

struct TrieNode *getNode(int wt) 
{ 
    struct TrieNode *pNode =  new TrieNode; 
    pNode->wt=wt;
    pNode->isEndOfWord = false; 
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
}

void insert(struct TrieNode *root, string key, int wt) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(wt); 
        pCrawl->wt=max(pCrawl->wt, wt);
        pCrawl = pCrawl->children[index]; 
    } 
  
    pCrawl->isEndOfWord = true; 
}

int search(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            return -1;
        pCrawl = pCrawl->children[index];
    } 
  
    return pCrawl->wt; 
}

int main()
{
    int q,n,wt;
    string str;
    cin>>n>>q; 
    struct TrieNode *root = getNode(-1);
    
    for(int i=0; i<n; i++)
    {
        cin>>str>>wt;
        insert(root , str, wt);
    }
    for(int i=0; i<q; i++)
    {
        cin>>str;
        cout<<search(root, str)<<"\n";
    }
}
