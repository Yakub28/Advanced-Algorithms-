#ifndef LINEAR_PROBING_HASH_TABLE_H
#define LINEAR_PROBING_HASH_TABLE_H

#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename Key, typename Value>
class LinearProbingHashTable
{
private:
    struct Entry
    {
        Key key;
        Value value;
        bool isEmpty;

        Entry() : isEmpty(true) {}
    };

    vector<Entry> table;
    size_t capacity;
    size_t size;

    size_t hashKey(const Key &key) const
    {
        return hash<Key>{}(key) % capacity;
    }

    size_t findIndex(const Key &key) const
    {
        size_t index = hashKey(key);
        size_t startIndex = index;
        while (!table[index].isEmpty && table[index].key != key)
        {
            index = (index + 1) % capacity;
            if (index == startIndex)
                throw out_of_range("Key not found!");
        }

        if (table[index].isEmpty)
            throw out_of_range("Key not found!");

        return index;
    }

public:
    LinearProbingHashTable(size_t tableSize) : capacity(tableSize), size(0)
    {
        table.resize(capacity);
    }

    void insert(const Key &key, const Value &value)
    {
        if (size == capacity)
            throw length_error("Table is full!");

        size_t index = hashKey(key);
        while (!table[index].isEmpty && table[index].key != key)
        {
            index = (index + 1) % capacity;
        }

        if (table[index].key == key)
        {
            table[index].value = value;
            table[index].isEmpty = false;
            return;
        }

        table[index].key = key;
        table[index].value = value;
        table[index].isEmpty = false;
        size++;
    }

    void remove(const Key &key)
    {
        size_t index = findIndex(key);
        table[index].isEmpty = true;
        size--;
    }

    Value &search(const Key &key)
    {
        size_t index = findIndex(key);
        return table[index].value;
    }
};

#endif // LINEAR_PROBING_HASH_TABLE_H