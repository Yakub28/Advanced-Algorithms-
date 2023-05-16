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

constexpr int step = 10;
constexpr int maxlen = 100;
constexpr int times = 10;

int main()
{
    std::cout << "Insert Time" << std::endl;
    std::cout << "Seperate Chaining"
              << " | "
              << "Linear Probing"
              << " | "
              << "Double Hashing" << std::endl;

    nanoseconds scht_insert_time(0);
    nanoseconds lpht_insert_time(0);
    nanoseconds dhht_insert_time(0);

    SeparateChainingHashTable<string, int> SCHashTable(10);
    LinearProbingHashTable<string, int> LPHashTable(10);
    DoubleHashingHashTable<string, int> DHHashTable(10);

    for (int t = 0; t < times; t++)
    {
        auto begin = std::chrono::steady_clock::now();
        SCHashTable.insert("key" + std::to_string(t), t);
        auto end = std::chrono::steady_clock::now();
        scht_insert_time += end - begin;

        begin = std::chrono::steady_clock::now();
        LPHashTable.insert("key" + std::to_string(t), t);
        end = std::chrono::steady_clock::now();
        lpht_insert_time += end - begin;

        begin = std::chrono::steady_clock::now();
        DHHashTable.insert("key" + std::to_string(t), t);
        end = std::chrono::steady_clock::now();
        dhht_insert_time += end - begin;
    }

    std::cout << scht_insert_time.count() / times << " | " << lpht_insert_time.count() / times << " | " << dhht_insert_time.count() / times << std::endl;

    std::cout << "Search Time" << std::endl;
    std::cout << "Seperate Chaining"
              << " | "
              << "Linear Probing"
              << " | "
              << "Double Hashing" << std::endl;

    nanoseconds scht_search_time(0);
    nanoseconds lpht_search_time(0);
    nanoseconds dhht_search_time(0);

    for (int t = 0; t < times; t++)
    {
        auto begin = std::chrono::steady_clock::now();
        SCHashTable.search("key" + std::to_string(t));
        auto end = std::chrono::steady_clock::now();
        scht_search_time += end - begin;

        begin = std::chrono::steady_clock::now();
        LPHashTable.search("key" + std::to_string(t));
        end = std::chrono::steady_clock::now();
        lpht_search_time += end - begin;

        begin = std::chrono::steady_clock::now();
        DHHashTable.search("key" + std::to_string(t));
        end = std::chrono::steady_clock::now();
        dhht_search_time += end - begin;
    }

    std::cout << scht_search_time.count() / times << " | " << lpht_search_time.count() / times << " | " << dhht_search_time.count() / times << std::endl;

    return 0;
}