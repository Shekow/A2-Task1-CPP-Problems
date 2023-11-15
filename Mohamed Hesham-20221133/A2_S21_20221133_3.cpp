// File: A2_S21_20221133_3.cpp
// Purpose: take sentance and remove the unwanted delimeter then split remiaining sentence in words
// Author: Mohamed Hesham
// Section: S21;
// ID: 20221133
// TA: Rana Abdelkader
// Date: 23 Oct 2023

#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<string> split(string target, string delimiter){
    string temp;
    vector<string> ans;
    for (int i = 0; i < target.size(); ++i) {
        temp.push_back(target[i]);

        if (temp.find(delimiter)!=string::npos){

            temp = temp . substr(0, temp.size()-delimiter.size() );
            ans . push_back( temp );
            temp="" ;
        }
    }
ans . push_back( temp ) ;
return ans;
};
signed main(){

    string target , delimiter;
    cout<<"enter target : ";
    getline(cin , target);
    cout<<"\n enter delimiter : ";
    getline(cin,delimiter);
    vector<string> answer = split(target ,delimiter );
    for (int i = 0; i < answer.size(); ++i) {
        cout<<answer[i]<<" ";
    }


}
