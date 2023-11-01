// File: A2_S21_20221081_2.cpp
// Purpose: Revising C++ Concepts
// Author: Sherif Youssef Mahmoud
// Section: S21
// ID: 20221081
// TA: Rana Abdelkader
// Date: 12 Oct 2023

#include <bits/stdc++.h>
#define ll long long
#define each auto &
#define endl '\n'
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
using namespace std;


void edit(string &s, string &a, string &b)
{
    ll start{};
    while (1)
    {
        ll l = s.find(a, start);
        if (!~l) break;
        ll r = l + a.length();
        start = r;
        if ((!l || !isalpha(s[l - 1])) && !isalpha(s[r])) 
        {
            s.insert(r, b);
            start += b.length();
        }
    }
}



int main()
{
    string s;
    getline(cin, s);
    vector<pair<string, string>> vec{{"he", " or she"}, {"his", " or her"}, {"him", " or her"}};
    for (each p: vec)
    {
        edit(s, p.first, p.second);
        p.first[0] -= 32;
        edit(s, p.first, p.second);
    }
    cout << s;
}