#include <algorithm>
#include <chrono>
#include <cassert>
#include <random>
#include <iostream>
#include <vector>
#include <string>

#include "./SeparateChainingHashTable.h"
#include "./LinearProbingHashTable.h"
#include "./DoubleHashingHashTable.h"

using std::chrono::nanoseconds;

int main()
{
    const int tableSize = 100;

    std::cout << "Insert Time" << std::endl;
    std::cout << "Load Factor"
              << " | "
              << "Seperate Chaining"
              << " | "
              << "Linear Probing"
              << " | "
              << "Double Hashing" << std::endl;

    nanoseconds scht_insert_time(0);
    nanoseconds lpht_insert_time(0);
    nanoseconds dhht_insert_time(0);

    SeparateChainingHashTable<string, int> SCHashTable1(tableSize);
    LinearProbingHashTable<string, int> LPHashTable1(tableSize);
    DoubleHashingHashTable<string, int> DHHashTable1(tableSize);

    for (int t = 0; t < tableSize - (0.04 * tableSize); t++)
    {
        auto begin = std::chrono::steady_clock::now();
        SCHashTable1.insert("key" + std::to_string(t), t);
        auto end = std::chrono::steady_clock::now();
        scht_insert_time = end - begin;

        begin = std::chrono::steady_clock::now();
        LPHashTable1.insert("key" + std::to_string(t), t);
        end = std::chrono::steady_clock::now();
        lpht_insert_time = end - begin;

        begin = std::chrono::steady_clock::now();
        DHHashTable1.insert("key" + std::to_string(t), t);
        end = std::chrono::steady_clock::now();
        dhht_insert_time = end - begin;

        std::cout << (double)t / tableSize << " | " << scht_insert_time.count() << " | " << lpht_insert_time.count() << " | " << dhht_insert_time.count() << std::endl;
    }

    std::cout << "Search Time" << std::endl;
    std::cout << "Load Factor"
              << " | "
              << "Seperate Chaining"
              << " | "
              << "Linear Probing"
              << " | "
              << "Double Hashing" << std::endl;

    nanoseconds scht_search_time(0);
    nanoseconds lpht_search_time(0);
    nanoseconds dhht_search_time(0);

    SeparateChainingHashTable<string, int> SCHashTable2(tableSize);
    LinearProbingHashTable<string, int> LPHashTable2(tableSize);
    DoubleHashingHashTable<string, int> DHHashTable2(tableSize);

    for (int t = 0; t < tableSize - (0.04 * tableSize); t++)
    {
        SCHashTable2.insert("key" + std::to_string(t), t);
        auto begin = std::chrono::steady_clock::now();
        SCHashTable2.search("key" + std::to_string(t));
        auto end = std::chrono::steady_clock::now();
        scht_search_time = end - begin;

        LPHashTable2.insert("key" + std::to_string(t), t);
        begin = std::chrono::steady_clock::now();
        LPHashTable2.search("key" + std::to_string(t));
        end = std::chrono::steady_clock::now();
        lpht_search_time = end - begin;

        DHHashTable2.insert("key" + std::to_string(t), t);
        begin = std::chrono::steady_clock::now();
        DHHashTable2.search("key" + std::to_string(t));
        end = std::chrono::steady_clock::now();
        dhht_search_time = end - begin;

        std::cout << (double)t / tableSize << " | " << scht_search_time.count() << " | " << lpht_search_time.count() << " | " << dhht_search_time.count() << std::endl;
    }
    
    return 0;
}