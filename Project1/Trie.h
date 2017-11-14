/**
 * @file Trie.h
 * @author Dennord
 * @date November 8, 2017
 * @brief File containing definitions for the Trie class
 */

#pragma once

#include <string>

class Trie {
	int nrEndWords; // number of words ending in the current node
	int nrTraversals; // number of words that passed through this node

	Trie *son[26]; // using only lowercase latin alphabet, 26 letters

	/**
	* @brief Actual delete method (Trie)
	* @param std::string
	* @return void
	* @details Deletes the word you give as std::string from the Trie
	*/
	void deleteFromTrie(std::string);

public:
	Trie();
	~Trie();

	/**
	 * @brief Insert method (Trie)
	 * @param std::string
	 * @return void
	 * @details Inserts the word you give as std::string into the Trie
	 */
	void insertWord(std::string);

	/**
	* @brief Delete + Check method (Trie)
	* @param std::string
	* @return void
	* @details Deletes the word you give as std::string from the Trie if the word exists
	*/
	void deleteWord(std::string);

	/**
	* @brief Print method (Trie)
	* @param std::string
	* @return void
	* @details Prints the words that start with the prefix you give as std::string from the Trie
	*/
	void showWordsWithPrefix(std::string);

	/**
	* @brief Print method (Trie)
	* @param std::string
	* @return bool
	* @details Tests if the word you give as std::string exists in Trie and returns true if it does, false otherwise.
	*/
	bool isInTrie(std::string);

	friend void showWord(Trie*, std::string);
};