#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>
#include <cassert>

#include "./DoubleHashingHashTable.h"

using namespace std;

int main()
{
    DoubleHashingHashTable<string, int> hashTable(10);

    hashTable.insert("apple", 5);
    hashTable.insert("banana", 7);
    hashTable.insert("orange", 3);

    try
    {
        hashTable.insert("apple", 5);
        assert(false);
    }
    catch (const invalid_argument &e)
    {
        assert(true);
    }

    assert(hashTable.search("apple") == 5);
    assert(hashTable.search("banana") == 7);

    hashTable.remove("banana");

    try
    {
        hashTable.search("banana");
        assert(false);
    }
    catch (const out_of_range &e)
    {
        assert(true);
    }

    return 0;
}