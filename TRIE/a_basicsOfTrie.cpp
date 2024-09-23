#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0 ;i<26 ;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }

};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root , string word){
        //Base Case
        if(word.length() ==0){
            root->isTerminal = true;
            return;
        }
        //All words will be in small letters
        int index = word[0] - 'a';
        TrieNode* child;
        
        //Present
        if(root -> children[index] != 0){
            child = root-> children[index];
        }
        else
        {
            /* Absent */
            child =new TrieNode(word[0]);
            root-> children[index] = child;

        }

        // Recursion
        insertUtil(child , word.substr(1));

    }

    void insertWord(string word){
        insertUtil(root , word);
    }


    bool searchUtil(TrieNode* root, string word){
        //Base Case
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0]-'a';
        TrieNode* child;

        if(root->children[index] != 0){
            child = root->children[index];
        }
        else{
            /// Absent
            return false;
        }
        //RECURSION
        return searchUtil(child , word.substr(1));

    }
    
    bool searchWord(string word){
        return searchUtil(root, word);
    }

    void removeUtil(TrieNode* &root , string word){
        //Base Case
        if(word.length()==0){
            return;
        }

        if (word.length() == 1) {
            int index = word[0] - 'a';
            TrieNode* child = root->children[index];
            if (child != nullptr && child->isTerminal) {
                child->isTerminal = false; // Mark as non-terminal
            }
            return;
        }   

        //RECURSION
        int index = word[0] - 'a';
        TrieNode* child = root->children[index];
        removeUtil(child, word.substr(1));
        
    }

    void removeWord(string word){
        removeUtil(root, word);
    }

};

int main(){
    Trie* t = new Trie();
    t->insertWord("abcd");
    t->insertWord("nilesh");
    t->insertWord("sarkar");
    t->insertWord("time");
    cout<<"Present or Not: "<< t->searchWord("nilesh")<<endl;

    t->removeWord("nilesh");
    cout<<"Present or Not: "<< t->searchWord("nilesh");

    return 0;
}