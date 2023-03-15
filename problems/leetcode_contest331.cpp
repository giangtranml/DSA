//
// Created by Tran Giang on 3/1/23.
//
#include "utils.cpp"
#include <iostream>
#include <queue>
#include <math.h>

using namespace std;
long long pickGifts(vector<int>& gifts, int k) {
    priority_queue<int> heap;
    for(auto gift: gifts){
        heap.push(gift);
    }
    long long res = 0;
    for (int i = 0; i < k; ++i) {
        int top = heap.top();
        heap.pop();

        top = sqrt(top);
        heap.push(top);
    }

    while(!heap.empty()){
        res += heap.top();
        heap.pop();
    }

    return res;
}

bool is_vowel(string word){
    int n = word.size()-1;
    return (word[0] == 'a' || word[0] == 'e' || word[0] == 'o' || word[0] == 'u' || word[0] == 'i')
        && (word[n] == 'a' || word[n] == 'e' || word[n] == 'o' || word[n] == 'u' || word[n] == 'i');
}

vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    vector<int> sums;
    sums.push_back(is_vowel(words[0]));
    int n = words.size();
    for (int i = 1; i < n; ++i) {
        sums.push_back(sums[i-1] + is_vowel(words[i]));
    }
    vector<int> res;
    for (auto query : queries) {
        int l = query[0];
        int r = query[1];
        int count = sums[r] - ((l>0) ? sums[l-1] : 0);
        res.push_back(count);
    }
    return res;
}

void solvep2(){
    string s;
    getline(cin, s);
    vector<string> words = split_string(s);
    int num_queries;
    cin >> num_queries;
    vector<vector<int>> queries;
    cin >> ws;
    for (int i = 0; i < num_queries; ++i) {
        getline(cin, s);
        vector<int> q;
        vector<string> sss = split_string(s);
        q.push_back(stoi(sss[0]));
        q.push_back(stoi(sss[1]));
        queries.push_back(q);
    };
    vector<int> res = vowelStrings(words, queries);
    print_1d_vector(res);
}