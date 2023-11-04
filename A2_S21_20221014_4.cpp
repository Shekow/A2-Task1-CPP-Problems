// File: A2_S21_20221014_Problem_4.cpp
// Purpose: Using sieve algorithm to get primes until n
// Author: Ahmed Yosry Saad
// Section: 21
// ID: 20221014
// TA: Rana Abdelkader
// Date: 1 Nov 2023
#include <iostream>
#include <bits/stdc++.h>
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


void sieve(vector<bool> &prime, ll MX)
{
    for (ll i{2}; i < MX; i++)
    {
        if (prime[i])
        {
            for (ll j{i * i}; j < MX; j += i) prime[j] = 0;
        }
    }
}


int main()
{

    ll n;
    cin >> n;
    vector<bool> prime(n + 1, true);
    sieve(prime, n + 1);
    for (ll i{2}; i <= n; i++)
    {
        if (prime[i]) cout << i << " ";
    }
}

