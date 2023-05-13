#ifndef Hash_H
#define Hash_H
#include <iostream>
#include <string>
#include <list>
#include <cmath>

using namespace std;

class HashMap
{
private:
	const static int hash_size = 2023;
	list<string> table[hash_size];

public:

	int hashFunc(string str)
	{
		int hash = 0;
		for (int i = 0; i <  str.length(); i++)
		{
			hash = hash + (int)pow(str[i], str.length() - i);
			hash = hash % hash_size;
		}
		return hash;
	
	}
    bool searchTable(string str)
	{
		int hash = hashFunc(str);
		list<string> &cell = table[hash];
		for (auto bucket = begin(cell); bucket != end(cell); bucket++)
		{
			if (*bucket == str)
				return true;
		}
		return false;
	}

	void insertString(string str)
	{
		int hash = hashFunc(str);
		list<string> &cell = table[hash];
		for (list<string>::iterator bucket = begin(cell); bucket != end(cell); bucket++)
		{
			if (*bucket == str)
				return;
		}

		cell.emplace_back(str);
	}
};
#endif