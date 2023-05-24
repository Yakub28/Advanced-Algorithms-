#ifndef SUNDAY_WILDCARD_H
#define SUNDAY_WILDCARD_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Processed
{
    vector<int> shift;
    int q_shift, s_shift, w_count, e_count;
};

Processed preprocess(string &pat)
{
    int q_shift = -1, s_shift = -1, w_count = 0, e_count = 0;
    int p_len = pat.length();

    vector<int> shift(256, p_len + 1);

    for (int i = 0; i < p_len; i++)
    {
        if (pat[i] == '?' && (i == 0 || pat[i - 1] != '\\'))
        {
            q_shift = p_len - i;
            w_count++;
        }
        else if (pat[i] == '*' && (i == 0 || pat[i - 1] != '\\'))
        {
            s_shift = p_len - i;
            w_count++;
        }
        else if (pat[i] == '\\' && (pat[i + 1] == '*' || pat[i + 1] == '?'))
        {
            i++;
            e_count++;
        }
        shift[pat[i]] = p_len - i;
    }

    Processed p = {shift, q_shift, s_shift, w_count, e_count};
    return p;
}

bool sunday(string pat, string txt)
{
    Processed p = preprocess(pat);

    int p_len = pat.length(),
        t_len = txt.length(),
        wildcard_count = p.w_count,
        question_shift = p.q_shift,
        star_shift = p.s_shift,
        escape_count = p.e_count;

    vector<int> shift = p.shift;

    int i = 0;
    while (i <= t_len - (p_len - escape_count))
    {
        int j, k = 0;

        for (j = 0; j < p_len; j++)
        {
            // Check for escape character '\'
            if (pat[j] == '\\')
            {
                j++;
                k++;
                if (txt[i + j - k] != pat[j])
                    break;
                continue;
            }
            if (pat[j] == '?')
            {
                continue;
            }
            else if (pat[j] == '*')
            {
                if (j == p_len - 1)
                    return true;
                // Skip consecutive '*' and '?' characters
                while (pat[j + 1] == '*' || pat[j + 1] == '?')
                {
                    j++;
                }
                // Recursive call for remaining pattern and text
                for (int y = 0; i + j + y < t_len; y++)
                {
                    if (sunday((pat.substr(j + 1)), (txt.substr(i + j + y - k))))
                    {
                        return true;
                    }
                }
                return false;
            }

            if (txt[i + j - k] != pat[j])
                break;
        }

        if (j == p_len)
        {
            return true;
        }
        if (i + p_len >= t_len)
        {
            break;
        }

        char c = txt[i + p_len - escape_count];
        if (wildcard_count == 0 || shift[c] < p_len + 1)
        {
            i += shift[c];
        }
        else if (star_shift == -1 || (question_shift != -1 && question_shift < star_shift))
        {
            i += question_shift;
            // cout << txt[i] << endl;
        }
        else if (star_shift != -1)
        {
            if (sunday(pat.substr(0, p_len - star_shift), txt.substr(i + 1, i + star_shift + 1)))
                if (sunday(pat.substr(p_len - star_shift), txt.substr(i + star_shift)))
                    return true;
            i += star_shift;
        }
    }

    return false;
}

#endif // SUNDAY_WILDCARD_H