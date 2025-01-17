#include<bits/stdc++.h>

class TrieNode{

  public:

  char data;
  int **children;
  bool isTerminal;

  TrieNode(){
    this->data = data;
    children = new TrieNode*[26];
    for(int i=0;i<26;i++){
      children[i] = NULL;
    }
    isTerminal = false;
  }
};