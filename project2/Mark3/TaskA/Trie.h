#ifndef Trie_H
#define Trie_H

#include <iostream>
#include <string>

using namespace std;

class Trie
{
	struct TrieNode
	{
		int frequency;
		struct TrieNode *children[127];

		TrieNode()
		{
			frequency = 0;
			for (int i = 0; i < 127; i++)
				children[i] = nullptr;
		}
	};
    
	TrieNode *root;
	unsigned int count;

public:
	Trie()
	{
		count = 0;
		root = nullptr;
	}

	void insert(const string &word)
	{
		if (root == nullptr)
			root = new TrieNode;
		TrieNode *nodePtr = root;
		for (int i = 0; i < word.length(); i++)
		{
			char c = word[i];
			if (nodePtr->children[c] == nullptr)
				nodePtr->children[c] = new TrieNode;
			nodePtr = nodePtr->children[c];
		}
		nodePtr->frequency++;
		count++;
	}

	int search(const string &word)
	{
		if (root == nullptr)
			return 0;
		TrieNode *nodePtr = root;
		for (int i = 0; i < word.length(); i++)
		{
			char c = word[i];
			if (nodePtr->children[c] == nullptr)
				return 0;
			nodePtr = nodePtr->children[c];
		}
		return nodePtr->frequency;
	}

	int size()
	{
		return count;
	}
	~Trie(){};
};

#endif