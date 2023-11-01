// File: A2_S21_20221081_11.cpp
// Purpose: Comparing files
// Author: Sherif Youssef Mahmoud
// Section: S21
// ID: 20221081
// TA: Rana Abdelkader
// Date: 1 Nov 2023

#include <bits/stdc++.h>
#define ll long long
#define each auto &
#define endl '\n'
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
using namespace std;


int main()
{
    string fileName1, fileName2, cont1, cont2;
    char op;
    cout << "First file: ";
    cin >> fileName1;
    cout << "Second file: ";
    cin >> fileName2;
    ifstream f1(fileName1), f2(fileName2);
    ostringstream oss1, oss2;
    oss1 << f1.rdbuf();
    oss2 << f2.rdbuf();
    cont1 = oss1.str(), cont2 = oss2.str();
    cout << "a-Character by character\n" << "b-Word by word\n";
    cout << "Response: ";
    cin >> op;
    if (op == 'a')
    {
        
        if (cont1 == cont2)
        {
            cout << "Identical" << endl;
        }
        else
        {
            cout << "Different" << endl;
            vector<pair<char, char>> line;
            for (ll i{}; i < cont1.size() && i < cont2.size() && cont1[i] != '\n' && cont2[i] != '\n'; i++)
            {
                if (cont1[i] != cont2[i]) line.push_back({cont1[i], cont2[i]});
            }
            if (line.size())
            {
                cout << "Number: " << line.size() << endl;
                cout << "Different content: \n";
                for (each d: line)
                {
                    cout << "\'" << d.first << "\' -> \'" << d.second << "\'" << endl;
                }
            }
        }
    }
    else if (op == 'b')
    {
        if (cont1 == cont2)
        {
            cout << "Identical" << endl;
        }
        else
        {
            cout << "Different" << endl;
            vector<string> words;
            string word;
            int wctr{}, lctr{1};
            for (each c: cont2)
            {
                if (c == '\t' || c == '\n' || c == ' ')
                {
                    if (!word.empty()) words.push_back(word), word.clear();
                }
                else word.push_back(c);
            }
            if (!word.empty()) words.push_back(word);
            word.clear();
            for (each c: cont1)
            {
                if (c == '\t' || c == '\n' || c == ' ')
                {
                    if (!word.empty())
                    {
                        if (wctr == words.size() || word != words[wctr])
                        {
                            cout << "Line number: " << lctr << endl;
                            cout << "Different word: \"" << word << "\" -> \"" << words[wctr] << "\"";
                            return 0;
                        }
                        wctr++;
                        word.clear();
                    }
                    if (c == '\n') lctr++;
                }
                else word.push_back(c);
            }
            cout << "Line number: " << lctr << endl;
            cout << "Different word: \"" << word << "\" -> \"" << words[wctr] << "\"";
        }
    }
}