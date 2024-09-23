#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i =0 ;i< 26 ;i++){
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(char ch){
        root = new TrieNode(ch);
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
            root-> childCount++;
            root-> children[index] = child;

        }

        // Recursion
        insertUtil(child , word.substr(1));

    }

    void insertWord(string word){
        insertUtil(root , word);
    }

    void lcp(string str ,string &ans){
        for(int i=0 ; i<str.length();i++){
            char ch = str[i];

            if(root->childCount ==1){
                ans.push_back(ch);
                //AAge BAdh jao
                int index = ch-'a';
                root= root->children[index];
            }
            
            else{
                break;
            }
            if(root->isTerminal ==true){
                break;
            }
        }
    }
};


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        Trie* t = new Trie('\0');
        for(int i=0; i< strs.size();i++){
            t->insertWord(strs[i]);

        }

        string first = strs[0];
        t-> lcp(first, ans);
        return ans;
    }
};