#include<bits/stdc++.h>
using namespace std;

struct node{
    unordered_map<char, node*>M;
    bool end;
};

class Trie {
public:
    node* root;
    Trie() {
        root = newnode();
    }
    node* newnode(){
        node *temp = new node;
        return (temp->end = false, temp);
    }

    void insert(string st){
        node *t = root = (root == nullptr?newnode():root);
        for(char x:st){
            if(t->M.find(x) == t->M.end())
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
};
