#include "trienode.h"

  TrieNode::TrieNode()
  {
    if(initArray())
    {
      resetIsWord();
      resetIsLeaf();
    }
    else
      cout << "\nCouldn't create object of class TrieNode (low on memory?)" << endl;
  }

// returns true if given node has any children
bool TrieNode::haveChildren()
{
  for (int i = 0; i < ALPHABET_SIZE; i++)
    if (this->symbolArray[i])
      return true;	// A child found

  return false;
}

bool TrieNode::initArray()
  {
      for (int i=0; i<ALPHABET_SIZE; i++)
        this->symbolArray[i] = nullptr;
      return true;
  }

TrieNode* TrieNode::getKeyI(int i)
{
  return this->symbolArray[i];
}

void TrieNode::setKeyI(int i, TrieNode* node)
{
  this->symbolArray[i] = node;
}

/*
void setDummyArray(TrieNode* rootptr, TrieNode* dummyptr)
{
  for (int i=0; i<ALPHABET_SIZE; i++)
    rootptr->symbolArray[i] = dummyptr;
}*/
