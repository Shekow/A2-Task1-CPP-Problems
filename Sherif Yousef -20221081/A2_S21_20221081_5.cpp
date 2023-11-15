// File: A2_S21_20221081_5.cpp
// Purpose: Storing and manipulating a list of players and their score
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
    multiset<pair<int, string>, greater<>> st;
    map<string, int> mp;
    while(1)
    {
        cout << "--------------------------------" << endl;
        cout << "1-Add a new player" << endl;
        cout << "2-Print the top 10 players and their score" << endl;
        cout << "3-Get the highest score of a specific player" << endl;
        cout << "--------------------------------" << endl;
        int op;
        cin >> op;
        if (op == 1)
        {
            string name;
            int score;
            cout << "Player Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Score: ";
            cin >> score;
            st.insert({score, name});
            mp[name] = max(mp[name], score);
        }
        else if (op == 2)
        {
            int ctr{};
            for (auto it{st.begin()}; it != st.end() && ctr < 10; it++, ctr++)
            {
                cout << it->second << ": " << it->first << endl;
            }
        }
        else if (op == 3)
        {
            string name;
            cout << "Player Name: ";
            cin.ignore();
            getline(cin, name);
            if (mp.count(name)) cout << "Highest score: " << mp[name] << endl;
            else cout << "This player doesn't exist." << endl;
        }
    }
}

