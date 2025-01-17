#include<bits/stdc++.h>
using namespace std;

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    Trie() { 
        root = new TrieNode('\0'); 
    }

    void insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        insertWord(child, word.substr(1));
    }

    void insertWord(string word) { 
        insertWord(root, word); 
    }

    bool search(string word) {
        return search(root, word);
    }

    void remove(string word){
      remove(root,word);
    }

    private:

    bool search(TrieNode* root, string word){
        if(word.size()==0){
            return root->isTerminal; // Checks if the last letter of word is Treminal or not
        }

        int index = word[0]-'a';
        TrieNode* Child;
        if(root->children[index]!=NULL){
            Child = root->children[index]; // if the letter is present head on to the next
        }else{
            return false; // if Not present return false
        }

        return search(Child, word.substr(1));  // recursive call to the child

    }

    void remove(TrieNode* root, string word){
      if(word.size()==0){
        root->isTerminal = false;
        return; 
      }

      TrieNode* Child;
      int index = word[0]-'a';
      if(root->children[index]!=NULL){
        Child = root->children[index];
      }else{
        return;
      }

      remove(Child,word.substr(1));

      if(Child -> isTerminal == false){
        for(int i=0;i<26;i++){
          if(Child->children[i]!=NULL){
            return;
          }
        }
        delete Child;
        root->children[index] = NULL; 
      }
    }
};

int main(){
  Trie t;
  t.insertWord("ant");
  t.insertWord("samsung");

  cout << t.search("ant") << endl;

  t.remove("ant");
  t.remove("samsung");

  cout << t.search("ant") << endl;
  cout << t.search("samsung") << endl;


}