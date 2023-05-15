#ifndef BBST_H
#define BBST_H

#include <iostream>
#include <string>

using namespace std;

class BBST
{
public:
	string value;
	int height;
	BBST *left;
	BBST *right;
    
	BBST(string val)
	{
		value = val;
		left = right = nullptr;
		height = 0;
	}

	int subtreeHeight(BBST *node)
	{
		if (node == nullptr)
			return 0;
		else
			return node->height;
	}

	int balanceFactor(BBST *node)
	{
		return subtreeHeight(node->right) - subtreeHeight(node->left);
	}

	void setBalance(BBST *node)
	{
		node->height = 1 + max(subtreeHeight(node->left), subtreeHeight(node->right));
	}

	BBST *rotateRight(BBST *node)
	{
		BBST *newNode = node->left;
		node->left = newNode->right;
		newNode->right = node;
		setBalance(node);
		setBalance(newNode);

		return newNode;
	}

	BBST *rotateLeft(BBST *node)
	{
		BBST *newNode = node->right;
		node->right = newNode->left;
		newNode->left = node;
		setBalance(node);
		setBalance(newNode);

		return newNode;
	}

	BBST *leftLeft(BBST *node)
	{
		node = rotateRight(node);
		return node;
	}

	BBST *rightRight(BBST *node)
	{
		node = rotateLeft(node);
		return node;
	}

	BBST *leftRight(BBST *node)
	{
		node->left = rotateLeft(node->left);
		node = leftLeft(node);
		return node;
	}

	BBST *rightLeft(BBST *node)
	{
		node->right = rotateLeft(node->right);
		return rightRight(node);
	}

	BBST *insert(BBST *parent, string val)
	{
		if (parent == nullptr)
			return new BBST(val);
		if (val < parent->value)
			parent->left = insert(parent->left, val);
		else if (val > parent->value)
			parent->right = insert(parent->right, val);

		if (balanceFactor(parent) == 2)
			return (balanceFactor(parent->right) >= 0 ? rightRight(parent) : rightLeft(parent));
		else if (balanceFactor(parent) == -2)
			return (balanceFactor(parent->left) <= 0 ? leftLeft(parent) : leftRight(parent));

		setBalance(parent);
		return parent;
	}

	bool search(BBST *parent, string val)
	{
		while (parent != nullptr)
		{
			if (val < parent->value)
				parent = parent->left;
			else if (val > parent->value)
				parent = parent->right;
			else if (val == parent->value)
				return true;
		}

		return false;
	}
};

#endif