// File: A2_S21_20221014_1.cpp
// Purpose: Printing sentences with correct capitalization and punctuation
// Author: Ahmed Yosry Saad
// Section: 21
// ID: 20221014
// TA: Rana Abdelkader
// Date: 1 Nov 2023

#include <bits/stdc++.h>
#define ll long long
#define each auto &
#define endl '\n'
#define pll pair<ll, ll>
#define all(v) v.begin(), v.end()
using namespace std;



int main(){
        string s ;
        string sentence;
        bool started = false;
        while (cin >> s ){
            for (int i = 0; i < s.size(); ++i) {
                s[i]= tolower(s[i]);
            }
            if (started){
                if (s==","||s=="."||s==":"){}
                else if (s[0]==','||s[0]==':'){char tmp = s[0];s[0]=' ';s=tmp+s;}
                else sentence+=" ";

                for (int i = 0; i < s.size(); ++i) {
                    if (i&&s[i]==','&& tolower(s[i-1])>='a'&& tolower(s[i+1])<='z'&&i+1!=s.size()){
                        s.insert(i+1," ");

                    }
                }
            }
            sentence+=s;
            started=true;


            if (sentence[sentence.size()-1]=='.'){sentence[0]= toupper(sentence[0]);cout << sentence;return 0;}
        }


}
