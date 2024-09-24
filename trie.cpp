#include<bits/stdc++.h>
using namespace std;
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord = false;
};

class Trie {
public:
    TrieNode* root = new TrieNode();
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }
    
    bool searchPrefix(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return true;
    }
};
