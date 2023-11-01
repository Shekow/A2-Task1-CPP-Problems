// File: A2_S21_20221081_8.cpp
// Purpose: Drawing a pattern on the screen
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


void pattern(ll n, ll s = 0)
{
    if (__popcount(n) != 1) return;
    pattern(n / 2, s);
    for (ll i{}; i < s; i++) cout << " ";
    for (ll i{}; i < n; i++) cout << "*";
    cout << endl;
    pattern(n / 2, s + n / 2);
}


int main()
{
    ll n;
    cout << "Size: ";
    cin >> n;
    pattern(n);
}

