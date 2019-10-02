#ifndef DICT_H
#define DICT_H
#include <bits/stdc++.h>
using namespace std;
class node {
public:
    bool isEndOfWord;
    unordered_map<char, node*> map;
    string meaning;
    node*getNewTrieNode(){
        node* nnode=new node;
         nnode->isEndOfWord=false;
         return nnode;
    }
   void insert(node*& root, const string& str,const string& meaning){
       if (root==NULL)
           root=getNewTrieNode();
        node*temp=root;
       for (int i=0;i<str.length();i++) {
          char x=str[i];
           if (temp->map.find(x)==temp->map.end())
              temp->map[x]=getNewTrieNode();
          temp=temp->map[x];
       }
      temp->isEndOfWord=true;
      temp->meaning=meaning;
    }
   string getMeaning(node* root,const string& word){
       if (root==NULL)
          return "";
       node* temp=root;
       for (int i=0;i<word.length();i++) {
           temp=temp->map[word[i]];
          if (temp==NULL)
              return "NOT FOUND";
         }
       if (temp->isEndOfWord)
          return temp->meaning;
       return "NOT FOUND";
    }
};
#endif // DICT_H
