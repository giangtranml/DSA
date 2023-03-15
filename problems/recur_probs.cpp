//
// Created by Tran Giang on 3/14/23.
//
#include <vector>
#include <string>
#include <iostream>
#include "utils.cpp"
using namespace std;

void powerSetRecur(string s, vector<string> &res, string curr="", int i=0){
    if(i == s.length()){
        res.push_back(curr);
        return;
    }
    powerSetRecur(s, res, curr, i+1);
    powerSetRecur(s, res, curr + s[i], i+1);
}

vector<string> powerSet(string s, vector<string> res={}){
    //Your code here
    powerSetRecur(s, res);
    return res;
}

void solvep(){
    string s;
    getline(cin, s);
    vector<string> res = powerSet(s);
    sort(res.begin(), res.end());
    print_1d_vector(res);
}