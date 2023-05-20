#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <windows.h>
#include <vector>
#include <regex>

#include "BBST.h"
#include "HashMap.h"
#include "Trie.h"

using namespace std;

int main()
{
    string word, textLine;
    ifstream wordFile("./data/words.txt"), textFile("./data/text.txt");
    ofstream searchResultsFile("./data/results_search.txt"), inputResultsFile("./data/results_input.txt");

    double totalNaiveTime(0), totalTreeTime(0), totalTrieTime(0), totalHashMapTime(0), dictionaryNaiveTime(0), dictionaryTreeTime(0), dictionaryTrieTime(0), dictionaryHashMapTime(0);

    vector<double> inputTimings{0, 0, 0, 0};
    vector<double> searchTimings{0, 0, 0, 0};

    BBST *tree = new BBST("a");
    Trie trie;
    HashMap hashMap;
    list<string> naiveList;

    LARGE_INTEGER frequency;
    LARGE_INTEGER start, end;
    double elapsedTime;

    // Dictionary building
    int wordCount = 0;
    int divider = 10;
    while (wordFile.peek() != EOF)
    {
        getline(wordFile, word);
        wordCount++;
    }
    wordFile.clear();
    wordFile.seekg(0);

    int i = 0;
    int j = 1;
    while (i < wordCount)
    {
        QueryPerformanceFrequency(&frequency);

        getline(wordFile, word);

        // Naive
        QueryPerformanceCounter(&start);
        naiveList.push_back(word);
        QueryPerformanceCounter(&end);
        dictionaryNaiveTime += (end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;

        // BBST
        QueryPerformanceCounter(&start);
        tree = tree->insert(tree, word);
        QueryPerformanceCounter(&end);
        dictionaryTreeTime += (end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;

        // Trie
        QueryPerformanceCounter(&start);
        trie.insert(word);
        QueryPerformanceCounter(&end);
        dictionaryTrieTime += (end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;

        // HashMap
        QueryPerformanceCounter(&start);
        hashMap.insertString(word);
        QueryPerformanceCounter(&end);
        dictionaryHashMapTime += (end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;

        i++;
        if ((wordCount / divider) * j == i)
        {
            inputResultsFile << (wordCount / divider) * j << "		" << dictionaryNaiveTime << "		" << dictionaryTrieTime << "	" << dictionaryTreeTime << "		" << dictionaryHashMapTime << endl;
            j++;
        }
    }

    // Search
    int searchCount = 0;
    vector<string> textWords;

    while (getline(textFile, textLine, ' '))
    {
        if (regex_match(textLine, regex("^[A-Za-z]+$")))
        {
            textWords.push_back(textLine);
            searchCount++;
        }
    }
    textFile.clear();
    textFile.seekg(0);

    int i1 = 0;
    int j1 = 1;
    while (i1 < searchCount)
    {
        QueryPerformanceFrequency(&frequency);

        word = textWords[i1];
        // Naive algorithm
        QueryPerformanceCounter(&start);
        for (list<string>::iterator it = naiveList.begin(); it != naiveList.end(); it++)
        {
            if (*it == word)
            {
                break;
            }
        }
        QueryPerformanceCounter(&end);
        totalNaiveTime += (end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;
        // BBST
        QueryPerformanceCounter(&start);
        tree->search(tree, word);
        QueryPerformanceCounter(&end);
        totalTreeTime += (end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;

        // Trie
        QueryPerformanceCounter(&start);
        trie.search(word);
        QueryPerformanceCounter(&end);
        totalTrieTime += (end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;

        // HashMap
        QueryPerformanceCounter(&start);
        hashMap.searchTable(word);
        QueryPerformanceCounter(&end);
        totalHashMapTime += (end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;

        i1++;
        if ((searchCount / divider) * j1 == i1)
        {
            searchResultsFile << (searchCount / divider) * j1 << "	" << totalNaiveTime << "	" << totalTrieTime << "	" << totalTreeTime << "	" << totalHashMapTime << endl;
            j1++;
        }
    }

    wordFile.close();
    textFile.close();
    return 0;
}
