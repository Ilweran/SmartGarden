/*
 * trie.cpp
 *
 *  Created on: Aug 3, 2019
 *      Author: Ilweran
 */
#include <iostream>
#include <stack>
#include "trie.h"
using namespace std;


string Trie::getName()
{
  return trieName;
}
// A Class representing a Trie node

// Iterative function to insert a key in the Trie
void Trie::insertString(string key)
{
  TrieNode* curr = root; 			// Start from the root node
  for (int i = 0; i < key.length(); i++)
  {
    if (curr->getKeyI(key[i] - 'a') == nullptr)		// Create a new node if path doesn't exist
      curr->setKeyI(key[i] - 'a', new TrieNode()); 	// Create a new TrieNode if curr is nullptr

    curr = curr->getKeyI(key[i] - 'a'); 		// Then jump to it
  }
    curr->setIsWord();
}

// Iterative function to search a key in a Trie. It returns true
// if the key is found in the Trie, else it returns false
bool Trie::searchString(string key)
{
  TrieNode* curr = root;

  for (int i = 0; i < key.length(); i++)
  {

    curr = curr->getKeyI(key[i] - 'a');		// Go to next node

    if (curr == nullptr)
      return false;
  }

  // If we have reached the end of the string, return true
  return curr->getIsWord();
}

// Recursive function to delete a key in the Trie
bool Trie::deleteString(TrieNode* curr, string key)
{
  // Return if the Trie is empty
  if (curr == nullptr)
    return false;

  stack<TrieNode*> mystack;
  mystack.push(curr);

  for (int i = 0; i < key.length(); i++)
  {
      curr = curr->getKeyI(key[i] - 'a');

      if(curr == nullptr)
	return false;

      mystack.push(curr);
  }							// Stack is filled

  if(curr->getIsWord() == false)
    return false;

  curr->resetIsWord();

  if(curr->haveChildren())				// Word is a prefix
    return true;

  mystack.pop();
  curr = mystack.top();
  mystack.pop();

  for(int i = key.length() - 1; i > 0; i--)
  {
    curr->setKeyI(key[i], nullptr);

    if(curr->getIsWord())
      return true;
    curr = mystack.top();
    mystack.pop();
  }
  return true;
}
