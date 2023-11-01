// File: A2_S21_20221133_6.cpp
// Purpose: solving problem 3 in Problem Sheet 1 – Version 2.0
// Author: Mohamed Hesham
// Section: S21;
// ID: 20221133
// TA: Rana Abdelkader
// Date: 23 Oct 2023

#include <iostream>
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void binaryPrint(int n, int mod = 1, string s = "")
{
    if (mod > n)
    {
        cout << s << endl;
        return;
    }
    if (n & mod)
    {
        s = "1" + s;
    }
    else
    {
        s = "0" + s;
    }
    mod *= 2;

    binaryPrint(n, mod, s);
}


void number(string &cu, int rem)
{
    if (rem == 0)
    {
        cout << cu << endl;
        return;
    }
    for (char c:{'0', '1'})
    {
        cu.push_back(c);
        number(cu , rem - 1 );
        cu.pop_back();
    }
}


int main()
{
    cout << "================\n";
    cout << "1-One Binary Number.\n";
    cout << "2-Printing Many Numbers.\n";
    cout << "================\n";
    int op;
    cin >> op;
    if (op == 1)
    {
        cout << "Number: ";
        int n;
        cin >> n;
        binaryPrint(n);
    }
    else if (op == 2)
    {
        string prefix;
        int k;
        cout << "Prefix : ";
        cin >> prefix;
        cout << "K : ";
        cin >> k;
        number(prefix, k);
}
}
