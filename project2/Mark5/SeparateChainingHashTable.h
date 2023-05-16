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

    typename list<KeyValuePair>::iterator it;

    size_t hashKey(const Key &key) const
    {
        return hash<Key>{}(key) % capacity;
    }

public:
    SeparateChainingHashTable(size_t tableSize) : capacity(tableSize)
    {
        table.resize(capacity);
    }

    void insert(const Key &key, const Value &value)
    {
        size_t index = hashKey(key);

        for (it = table[index].begin(); it != table[index].end(); ++it)
        {
            if (it->key == key)
            {
                it->value = value;
                return;
            }
        }

        table[index].push_back(KeyValuePair(key, value));
    }

    void remove(const Key &key)
    {
        size_t index = hashKey(key);
        list<KeyValuePair> &entry = table[index];
        for (it = entry.begin(); it != entry.end(); ++it)
        {
            if (it->key == key)
            {
                entry.erase(it);
                return;
            }
        }
    }

    Value &search(const Key &key)
    {
        size_t index = hashKey(key);
        list<KeyValuePair> &entry = table[index];
        for (it = entry.begin(); it != entry.end(); ++it)
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