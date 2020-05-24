// Author :: <Hitesh_Saini>
#include<bits/stdc++.h>
using namespace std;

struct trie{
    unordered_map<char, trie*>M;
    bool end;
} *root;
typedef trie node;

node* newnode(){
    node *temp = new node;
    return (temp->end = false, temp);
}

void insert(string st){
    node *t = root = (root == nullptr?newnode():root);
    for(char x:st){
        if(t->M.find(x)==t->M.end())
            t->M[x] = newnode();
        t = t->M[x];
    }
    t->end = true;
}

bool search(string st){
    node *t=root;
    for(char x:st){
        if(t==nullptr || t->M[x]==nullptr)
            return false;
        t = t->M[x];
    }
    return t->end;
}

int main(){
    insert("dog");
    insert("cat");
    insert("dogos");
    insert("cattie");
    insert("catsdog");
    cout<<boolalpha<<search("cattie");
    return 0;
}
