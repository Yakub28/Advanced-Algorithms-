#ifndef RABIN_KARP_2D_H
#define RABIN_KARP_2D_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool rabin_karp(int K, vector<vector<int>> &picture){
    int M = picture.size(), N = picture[0].size();
    
    int S = 127;// Prime base for hashing
    int hP = 0, hT = 0; // Hash values for pattern and text
    for (int i = 0; i < K; i++) {
        for (int j = N - K; j < N; j++) {
            hP = (hP * S + picture[i][j]) & ((1 << 16) - 1); // Calculate hash value for pattern
            hT = (hT * S + picture[i + M - K][j]) & ((1 << 16) - 1); // Calculate hash value for text
        }
    }

    if (hP == hT) return true;// If the hash values match, pattern is found at the initial position

    int spow = 1;// Power of base used for rolling hash calculation
    for (int i = 1; i < K; i++) spow = (spow * S) & ((1 << 16) - 1);

    for (int i = K; i < M; i++) {
        int old_P = (hP * spow) & ((1 << 16) - 1);// Previous hash value for pattern
        int old_T = (hT * spow) & ((1 << 16) - 1);// Previous hash value for text
        for (int j = N - K; j < N; j++) {
            hP = ((hP << 7) + picture[i][j] - old_P) & ((1 << 16) - 1);// Update hash value for pattern
            hT = ((hT << 7) + picture[i + M - K][j] - old_T) & ((1 << 16) - 1);// Update hash value for text
        }
        if (hP == hT) return true;
    }

    return false;
}

#endif  // RABIN_KARP_2D_H