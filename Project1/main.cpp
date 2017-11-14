/**
* @file main.cpp
* @author Dennord
* @date November 8, 2017
* @brief Driver program for Trie testing
*/

#include <iostream>
#include "Trie.h"

using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// Instantiating the root of the Trie
	Trie *root = new Trie();

	// Inserting words "teemo" and "teeara"
	root->insertWord(string("teemo"));
	root->insertWord(string("teeara"));

	// Checking if "teemo" exists in Trie
	cout << "Word \"teemo\" is " << (root->isInTrie("teemo") ? "" : "NOT ") << "in the trie!\n\n";
	
	// Showing all the words beginning with "tee"
	root->showWordsWithPrefix(string("tee"));

	// Deleting "teemo" and attempting to delete "teeeeee"
	root->deleteWord(string("teemo"));
	root->deleteWord(string("teeeeee"));

	root->showWordsWithPrefix(string("tee"));

	cout << "Word \"teemo\" is " << (root->isInTrie("teemo") ? "" : "NOT ") << "in the trie!\n\n";

	// Deleting the root to avoid memory leaks
	delete root;

	system("pause");

	return 0;
}