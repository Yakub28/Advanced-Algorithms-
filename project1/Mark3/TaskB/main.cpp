#include <algorithm>
#include <chrono>
#include <cassert>
#include <random>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "Sunday.h"
#include "KMP.h"
#include "RabinKarp.h"
#include "GusfieldZ.h"

using std::chrono::nanoseconds;

constexpr int step = 10;
constexpr int maxlen = 100;
constexpr int times = 10;

nanoseconds timeit(string &pat, string &txt, vector<int> what(string &, string &))
{
    auto begin = chrono::steady_clock::now();
    what(pat, txt);
    auto end = chrono::steady_clock::now();

    nanoseconds total(end - begin);
    return total;
}

void printResult(string name, string &pat, string &txt, vector<int> what(string &, string &))
{
    cout << name << " : ";
    vector<int> result = what(pat, txt);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

string readFileAsString(const string &file_path)
{
    const ifstream input_stream(file_path, ios_base::binary);

    if (input_stream.fail())
        throw runtime_error("Failed to open file");

    stringstream buffer;
    buffer << input_stream.rdbuf();

    return buffer.str();
}

int main()
{
    // Case 1 : Binary Sunday (the first algorithms covered in class) is at least twice as fast as Gusfield Z.
    // The Theory : When text is very long and pattern is short Sunday should perform twice as fast as Gusfield Z.
    // Because, the Sunday algorithm has a linear time complexity in the average case, while the Gusfield Z algorithm
    // has a worst-case time complexity of O(m + n), where m is the length of the pattern and n is the length of the text.

    string text1 = readFileAsString("./data/text1.txt");

    string pattern1 = readFileAsString("./data/pattern1.txt");

    cout << "Sunday"
         << " | "
         << "Gusfield Z" << endl;

    nanoseconds sunday_time(0);
    nanoseconds gusfield_z_time(0);

    for (int t = 0; t < times; t++)
    {
        sunday_time += timeit(pattern1, text1, &sunday);
        gusfield_z_time += timeit(pattern1, text1, &gusfield_z);
    }

    cout << sunday_time.count() / times << " | " << gusfield_z_time.count() / times << endl;

    // Case 2 : KMP is at least twice as fast as Rabin-Karp.

    string text2 = readFileAsString("./data/text2.txt");

    string pattern2 = readFileAsString("./data/pattern2.txt");

    cout << "KMP"
         << " | "
         << "Rabin Karp" << endl;

    nanoseconds kmp_time_2(0);
    nanoseconds rabin_karp_time_2(0);

    for (int t = 0; t < times; t++)
    {
        kmp_time_2 += timeit(pattern2, text2, &kmp);
        rabin_karp_time_2 += timeit(pattern2, text2, &rabin_karp);
    }

    cout << kmp_time_2.count() / times << " | " << rabin_karp_time_2.count() / times << endl;

    // Case 3 : Rabin-Karp is at least twice as fast as Sunday

    string text3 = readFileAsString("./data/text3.txt");

    string pattern3 = readFileAsString("./data/pattern3.txt");

    cout << "Rabin Karp"
         << " | "
         << "Sunday" << endl;

    nanoseconds rabin_karp_time_3(0);
    nanoseconds sunday_time_3(0);

    for (int t = 0; t < times; t++)
    {
        rabin_karp_time_3 += timeit(pattern3, text3, &rabin_karp);
        sunday_time_3 += timeit(pattern3, text3, &sunday);
    }

    cout << rabin_karp_time_3.count() / times << " | " << sunday_time_3.count() / times << endl;

    return 0;
}