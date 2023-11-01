// File: A2_S21_20221133_9.cpp
// Purpose: determine if a player can win a game if  they start with a given number 'n' with goal to reach 42 after some operations
// Author: Mohamed Hesham
// Section: S21
// ID: 20221133
// TA: Rana Abdelkader
// Date: 24 Oct 2023

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#define ll long long

using namespace std;

bool can_win(int n ){
    if (n==42) return true;
    if (n<42)
        return false;
    if (n%2==0)
        if (can_win(n/2))
            return true;

    if (n%3==0 || n%4==0)
        if (can_win(n - ((n % 10) * ((n % 100) / 10))))return true;

    if (n%5==0){ if (can_win(n-42))return true;}

    return false;
}
int main()
{
    int n;
    cout << "Enter a number : " ;
    cin>>n;
    if(can_win(n)){
cout<<"You can Win ";
    }
    else{
        cout<<"You can't Win ";
    }
}