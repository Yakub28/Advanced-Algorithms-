#include <algorithm>
#include <chrono>
#include <cassert>
#include <random>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "./SeparateChainingHashTable.h"
#include "./LinearProbingHashTable.h"
#include "./DoubleHashingHashTable.h"

using std::chrono::nanoseconds;

int main()
{
    srand((unsigned)time(NULL));

    const int tableSize = 10000;
    const int times = 10000;

    ofstream insert_results("./data/insert.txt");

    insert_results << "Load Factor"
                   << ","
                   << "Seperate Chaining"
                   << ","
                   << "Linear Probing"
                   << ","
                   << "Double Hashing" << endl;

    nanoseconds scht_insert_time(0);
    nanoseconds lpht_insert_time(0);
    nanoseconds dhht_insert_time(0);

    SeparateChainingHashTable<string, int> SCHashTable1(tableSize);
    LinearProbingHashTable<string, int> LPHashTable1(tableSize);
    DoubleHashingHashTable<string, int> DHHashTable1(tableSize);

    for (int t = 0; t < tableSize - (0.02 * tableSize); t++)
    {
        scht_insert_time = nanoseconds(0);
        lpht_insert_time = nanoseconds(0);
        dhht_insert_time = nanoseconds(0);

        for (int i = 0; i < times; i++)
        {
            string key = std::to_string(rand());

            auto begin = std::chrono::steady_clock::now();
            SCHashTable1.insert(key, t);
            auto end = std::chrono::steady_clock::now();
            scht_insert_time += end - begin;

            begin = std::chrono::steady_clock::now();
            LPHashTable1.insert(key, t);
            end = std::chrono::steady_clock::now();
            lpht_insert_time += end - begin;

            begin = std::chrono::steady_clock::now();
            DHHashTable1.insert(key, t);
            end = std::chrono::steady_clock::now();
            dhht_insert_time += end - begin;

            if (i < times - 1)
            {
                SCHashTable1.remove(key);
                LPHashTable1.remove(key);
                DHHashTable1.remove(key);
            }
        }

        insert_results << (double)t / tableSize << "," << scht_insert_time.count() / times << "," << lpht_insert_time.count() / times << "," << dhht_insert_time.count() / times << endl;
    }

    ofstream search_results("./data/search.txt");

    search_results << "Load Factor"
                   << ","
                   << "Seperate Chaining"
                   << ","
                   << "Linear Probing"
                   << ","
                   << "Double Hashing" << std::endl;

    nanoseconds scht_search_time(0);
    nanoseconds lpht_search_time(0);
    nanoseconds dhht_search_time(0);

    SeparateChainingHashTable<string, int> SCHashTable2(tableSize);
    LinearProbingHashTable<string, int> LPHashTable2(tableSize);
    DoubleHashingHashTable<string, int> DHHashTable2(tableSize);

    for (int t = 0; t < tableSize - (0.02 * tableSize); t++)
    {
        scht_search_time = nanoseconds(0);
        lpht_search_time = nanoseconds(0);
        dhht_search_time = nanoseconds(0);

        SCHashTable2.insert(std::to_string(rand()), t);
        LPHashTable1.insert(std::to_string(rand()), t);
        DHHashTable1.insert(std::to_string(rand()), t);

        for (int i = 0; i < times; i++)
        {
            string key = std::to_string(rand());

            auto begin = std::chrono::steady_clock::now();
            try
            {
                SCHashTable1.search(key);
            }
            catch (out_of_range &msg)
            {
                // do nothing
            }
            auto end = std::chrono::steady_clock::now();
            scht_search_time += end - begin;

            begin = std::chrono::steady_clock::now();
            try
            {
                LPHashTable1.search(key);
            }
            catch (out_of_range &msg)
            {
                // do nothing
            }
            end = std::chrono::steady_clock::now();
            lpht_search_time += end - begin;

            begin = std::chrono::steady_clock::now();
            try
            {
                DHHashTable1.search(key);
            }
            catch (out_of_range &msg)
            {
                // do nothing
            }
            end = std::chrono::steady_clock::now();
            dhht_search_time += end - begin;
        }

        search_results << (double)t / tableSize << " | " << scht_search_time.count() / times << " | " << lpht_search_time.count() / times << " | " << dhht_search_time.count() / times << endl;
    }

    return 0;
}