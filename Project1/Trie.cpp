/**
* @file Trie.cpp
* @author Dennord
* @date November 8, 2017
* @brief File containing implementations for the Trie class defined in Trie.h
*/

#include "Trie.h"
#include <iostream>

Trie::Trie() {
	nrEndWords = 0;
	nrTraversals = 0;

	for (int i = 0; i < 26; ++i)
		son[i] = NULL;
}

Trie::~Trie() {
	for (int i = 0; i < 26; ++i)
		if (son[i] != NULL)
			delete son[i];
}

void Trie::insertWord(std::string word) {
	++nrTraversals;

	if (word.length() == 0) {
		++nrEndWords;
		return;
	}

	if (son[word[0] - 'a'] == NULL)
		son[word[0] - 'a'] = new Trie();

	son[word[0] - 'a']->insertWord(word.substr(1));
}

void Trie::deleteFromTrie(std::string word) {
	if (nrTraversals > 0) --nrTraversals;

	if (word.length() == 0) {
		--nrEndWords;
		return;
	}

	if (son[word[0] - 'a'] == NULL)
		return;

	if (son[word[0] - 'a']->nrTraversals == 0)
		delete son[word[0] - 'a'];

	son[word[0] - 'a']->deleteWord(word.substr(1));
}

void Trie::deleteWord(std::string word) {
	if (isInTrie(word)) deleteFromTrie(word);
	else std::cout << "Word " + word + " not in Trie!\n\n";
}

std::string resultedWord = "";
int cntWords = 0;

void showWord(Trie *node, std::string result) {
	for (int i = 0; i < 26; ++i) {
		if (node->son[i] == NULL) continue;
		showWord(node->son[i], result + char('a' + i));
	}

	for (int i = 0; i < node->nrEndWords; ++i, ++cntWords)
		std::cout << cntWords << ". " << result << "\n";
}

void Trie::showWordsWithPrefix(std::string word) {
	if (word.length() == 0) {
		cntWords = 0;
		resultedWord = "";

		showWord(this, resultedWord);
		std::cout << "\n";

		return;
	}

	if (son[word[0] - 'a'] != NULL) {
		resultedWord += word[0];
		son[word[0] - 'a']->showWordsWithPrefix(word.substr(1));
	}
	else {
		std::cout << "Word is not in trie!\n";
		return;
	}
}

bool Trie::isInTrie(std::string word) {
	if (word.length() == 0) return (nrEndWords > 0);

	if (son[word[0] - 'a']) return son[word[0] - 'a']->isInTrie(word.substr(1));
	else return false;
}
