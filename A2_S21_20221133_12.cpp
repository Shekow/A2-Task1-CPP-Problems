// File: A2_S21_20221133_12.cpp
// Purpose: solving problem 12 in Problem Sheet 1 – Version 2.0
// Author: Mohamed Hesham
// Section: S21;
// ID: 20221133
// TA: Rana Abdelkader
// Date: 24 Oct 2023

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#define ll long long

using namespace std;


int appearances(string word , string phrase){
    int ans =0;
    int s1 = phrase.size();
    int s2 = word.size();

    for (int i = 0; i <s1 ; ++i) {
        if (phrase[i]== tolower(word[1])||phrase[i]== toupper(word[1])){

            int cnt =1;

            for (int j = i; j <i+s2 ; ++j) {
                if (phrase[j]!= tolower(word[j-i+1])&&phrase[j]!= toupper(word[j-i+1])){

                    cnt=0;
                    break;
                }
            }
            ans+=cnt;

        }
    }
    return ans;

}


int main()
{
    map<string , int > val ;
    const int Size=30;
    string Phrases [Size];
    ifstream inputfile ("Phishing words.txt");
    int value{} ;
    string s{} ;
    for (auto & Phrase : Phrases) {
        inputfile>> value;
        getline(inputfile,s);
        Phrase=s;
        val[Phrase]=value;
    }
    ifstream input2file("Input.txt");
    string in ;
    map<string,int>occ;
    ll total_points =0;
    while (getline(input2file,in)) {

        for (auto & Phrase : Phrases) {
            int res=appearances(Phrase,in);

            occ[Phrase]+=res;
            total_points+=(res*val[Phrase]);
        }


    }
    cout<<"Total score of phishing = " << total_points<<endl;
    if (total_points){

        cout <<"List of some suspicious words\n";
    }
    for (const auto& p:occ) {
        if (p.second){
            cout <<"Total appearances of the phrase :"<< p.first <<". is "<< p.second <<" with total score = "<<p.second*val[p.first]<<endl;
        }
    }
}
