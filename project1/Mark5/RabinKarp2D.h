#ifndef RABIN_KARP_2D_H
#define RABIN_KARP_2D_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool rabin_karp(int K, vector<vector<int>> &picture)
{
    int M = picture.size(), N = picture[0].size();

    int S = 127, L = ((1 << 16) - 1);
    int hP = 0, hT = 0; // Hash values for pattern and text
    for (int i = 0; i < K; i++)
    {
        for (int j = N - K; j < N; j++)
        {
            hP = ((hP * S) & L + picture[i][j]) & L;
            hT = ((hT * S) & L + picture[i][j]) & L;
        }
    }

    int spow = 1;
    for (int i = 1; i < K; i++)
        spow = (spow * S) & L;

    for (int i = 0; i <= M - K; i++)
    {
        int j;
        if (i % 2 == 0)
        {
            for (j = N - K - 1; j >= 0; j--)
            {
                for (int p = 0; p < K; p++)
                {
                    hT = (hT - (picture[i + p][j + K] * spow & L) + L) & L;
                    hT = ((hT * S) & L + picture[i + p][j]) & L;
                }
            }
            if (i != M - K)
            {
                for (int p = 0; p < K; p++)
                {
                    hT = (hT - (picture[i][j + p] * spow & L) + L) & L;
                    hT = ((hT * S) & L + picture[i + K][j + p]) & L;
                }
            }
        }
        else
        {
            for (j = 0; j <= N - K - 1; j++)
            {
                for (int p = 0; p < K; p++)
                {
                    hT = (hT - (picture[i + p][j] * spow & L) + L) & L;
                    hT = ((hT * S) & L + picture[i + p][j + K]) & L;
                }
            }
            if (i != M - K)
            {
                for (int p = 0; p < K; p++)
                {
                    hT = (hT - (picture[i][j + p] * spow & L) + L) & L;
                    hT = ((hT * S) & L + picture[i + K][j + p]) & L;
                }
            }
        }

        if (hP == hT)
            return true;
    }

    return false;
}

#endif // RABIN_KARP_2D_H