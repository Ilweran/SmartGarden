#include <iostream>
#include <cstdint>

#define ALPHABET_SIZE 26 //English ABC
using namespace std;
constexpr uint8_t isWord{ 1 << 0 };
constexpr uint8_t isLeaf{ 1 << 1 };

class TrieNode
{
public:
  TrieNode();
  TrieNode(TrieNode*);

  ~TrieNode(){}

  bool getIsLeaf() { return (flags & isLeaf); }
  bool getIsWord() { return (flags & isWord); }
  void setIsLeaf() { flags |= isLeaf; }
  void setIsWord() { flags |= isWord; }
  void resetIsLeaf() { flags &= ~isLeaf; }
  void resetIsWord() { flags &= ~isWord; }
  bool haveChildren();
  bool initArray();
  TrieNode* getKeyI(int i);
  void setKeyI(int i, TrieNode* node);	// Add some sort of assertion here (could create object?)

private:
  TrieNode* symbolArray[ALPHABET_SIZE];
  uint_fast8_t flags;
};
