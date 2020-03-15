//
//  main.cpp
//  SuffixTrie
//
//  Created by adeeb mohammed on 09/03/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <string>

/*
    program for storing string in a tri tree
    the time complexity of the tri tree inertion =
    the space complextiy of the tree tree insertion =
    the search complexity of the tri tree =
 
    here we are implementing a tri suffix tree
    we have a large string and we create a suffix treee
    and we search for an array of string and check whether the
    large string contains these small string

    a trie tree such that each node contains a map of
    characters point to another trie node
 
    trie is a data structure for string suffix prefix matches.
 
 */

class TrieNode {
public:
  std::unordered_map<char, TrieNode *> children;
};

class SuffixTrie {
public:
    TrieNode *root;
    char endSymbol;

    // initial trie construction
    SuffixTrie(std::string str) {
        this->root = new TrieNode();
        this->endSymbol = '*';
        this->populateSuffixTrieFrom(str);
    }
    
    void populateSuffixTrieFrom(std::string str) {
        for(int i = 0; i < str.size(); i++){
            this->insertSubtringAtPos(i, str);
        }
    }

    // this function is for inserting substring o(n2)
    void insertSubtringAtPos(int pos, std::string str){
        TrieNode *oneNode = this->root;
        for(int  i = pos; i < str.size(); i++){
            char ch = str.at(i);
            if(oneNode->children.find(ch) == oneNode->children.end()){
                oneNode->children.insert({ch,new TrieNode()});
            }
            oneNode = oneNode->children[ch];
        }
        oneNode->children.insert({this->endSymbol,nullptr});
    }
    
    // search time is o(n) space complexity is o(1)
    bool contains(std::string str) {
        TrieNode *oneNode = this->root;
        for(int i = 0; i < str.size(); i++){
            char ch = str.at(i);
            if(oneNode->children.find(ch) == oneNode->children.end()){
                return false;
            }
            oneNode = oneNode->children[ch];
        }
        return oneNode->children.find(this->endSymbol) != oneNode->children.end() ? true:false;
    }
};


int main(int argc, const char * argv[]) {
    SuffixTrie oSuffixTrie("ADEEB");
    std::cout << oSuffixTrie.contains("EB") << std::endl;
    std::cout<< "";
    return 0;
}
