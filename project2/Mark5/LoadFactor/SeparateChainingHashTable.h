#ifndef SEPARATE_CHAINING_HASH_TABLE_H
#define SEPARATE_CHAINING_HASH_TABLE_H

#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename Key, typename Value>
class SeparateChainingHashTable
{
private:
    struct KeyValuePair
    {
        Key key;
        Value value;

        KeyValuePair(const Key &k, const Value &v) : key(k), value(v) {}
    };

    vector<list<KeyValuePair>> table;
    size_t capacity;
    size_t size;

    // typename list<KeyValuePair>::iterator it;

    size_t hashKey(const Key &key) const
    {
        return hash<Key>{}(key) % capacity;
    }

    double getLoadFactor() const
    {
        return (double)size / capacity;
    }

    void resizeTable(size_t newCapacity)
    {
        vector<list<KeyValuePair>> oldTable = table;
        capacity = newCapacity;
        table.clear();
        table.resize(capacity);
        size = 0;

        for (size_t i = 0; i < oldTable.size(); i++)
        {
            for (auto it = oldTable[i].begin(); it != oldTable[i].end(); ++it)
            {
                insert(it->key, it->value);
            }
        }
    }

public:
    SeparateChainingHashTable(size_t tableSize) : capacity(tableSize), size(0)
    {
        table.resize(capacity);
    }

    void insert(const Key &key, const Value &value)
    {
        size_t index = hashKey(key);

        for (auto it = table[index].begin(); it != table[index].end(); ++it)
        {
            if (it->key == key)
            {
                it->value = value;
                return;
            }
        }

        table[index].push_back(KeyValuePair(key, value));
        size++;

        if (getLoadFactor() > 0.75)
            resizeTable(capacity * 2);
    }

    void remove(const Key &key)
    {
        size_t index = hashKey(key);
        list<KeyValuePair> &entry = table[index];
        for (auto it = entry.begin(); it != entry.end(); ++it)
        {
            if (it->key == key)
            {
                entry.erase(it);
                return;
            }
        }
        size--;

        if (getLoadFactor() < 0.25)
            resizeTable(capacity / 2);
    }

    Value &search(const Key &key)
    {
        size_t index = hashKey(key);
        list<KeyValuePair> &entry = table[index];
        for (auto it = entry.begin(); it != entry.end(); ++it)
        {
            if (it->key == key)
            {
                return it->value;
            }
        }
        throw out_of_range("Key not found!");
    }
};

#endif // SEPARATE_CHAINING_HASH_TABLE_H