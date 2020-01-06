/*
 * auxlib.cpp
 *
 *  Created on: 5 Jan 2020
 *      Author: Ilweran
 */

#include "auxlib.h"
#include "trie.h"
#include "inputhandler.h"
#include <iostream>
#include <string>
using namespace std;

void input_and_store_Word()
{
  cout << "Input a word: ";
  string s;
  getline(cin, s);
  Trie* oak = new Trie();
  oak->insertString(s);
  cout << "inserted \"" << s << "\"";
}
