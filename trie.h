/*
 * trie.h
 *
 *  Created on: Aug 3, 2019
 *      Author: Ilweran
 */

#ifndef TRIE_H_
#define TRIE_H_

#include<iostream>
#include <string>
#include "trienode.h"
using namespace std;

class Trie
{
public:
  Trie()
  {
    root = new TrieNode();
    trieName = "English";
  }

  Trie(string s)
    {
      root = new TrieNode();
      trieName = s;
    }

  ~Trie()
  {
    
  }

  void insertString(string);
  bool deleteString(TrieNode* , string);
  bool searchString(string);
  string getName();

private:
  TrieNode* root;
  string trieName;
};


#endif /* TRIE_H_ */
