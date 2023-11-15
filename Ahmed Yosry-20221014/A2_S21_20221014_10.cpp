// File: A2_S21_20221014_10.cpp
// Purpose: Getting alternatives for arabic words which can be censored by the platform
// Author: Ahmed Yosry Saad
// Section: 21
// ID: 20221014
// TA: Rana Abdelkader
// Date: 1 Nov 2023


#include <iostream>
#include <bits/stdc++.h>
#include <io.h>
#include <fcntl.h>
#include <random>
#include <time.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define each auto &
#define endl '\n'
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
#define INF LONG_LONG_MAX
#define Outsiders freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
using namespace std;


int main()
{
    srand(time(NULL));
    string dictFileName, fileName;
    wstring word, line, cenContent;
    map<wstring, vector<wstring>> dict;
    cout << "Dictonary file name: ";
    cin >> dictFileName;
    cout << "Filename: ";
    cin >> fileName;

    wifstream fs(dictFileName);
    _setmode(_fileno(stdout),_O_U8TEXT);
    _setmode(_fileno(stdin),_O_U8TEXT);
    while (fs >> word)
    {
        wstring alts, alt;
        getline(fs , alts);
        for (each c: alts)
        {
            if (c == ' ')
            {
                if (!alt.empty()) dict[word].push_back(alt), alt.clear();
            }
            else alt.push_back(c);
        }
        if (!alt.empty()) dict[word].push_back(alt);
    }

    word.clear();
    fs.close();
    fs.open(fileName);

    while (getline(fs, line))
    {
        for (each c: line)
        {
            if (c == ' ')
            {
                if (dict.count(word))
                {
                    int random_idx = rand() % dict[word].size();
                    cenContent += dict[word][random_idx];
                }
                else cenContent += word;
                word.clear();
                cenContent.push_back(' ');
            }
            else word.push_back(c);
        }
        if (dict.count(word))
        {
            int random_idx = rand() % dict[word].size();
            cenContent += dict[word][random_idx];
        }
        else cenContent += word;
        word.clear();
        cenContent.push_back('\n');
    }

    freopen(fileName.c_str(), "w", stdout);
    wcout << cenContent;
}
