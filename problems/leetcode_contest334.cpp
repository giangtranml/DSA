//
// Created by Tran Giang on 2/27/23.
//
#include "utils.cpp"
#include <iostream>

using namespace std;

int sum(vector<int> arr){
    int sum = 0;
    for(auto a: arr){
        sum += a;
    }
    return sum;
}

vector<int> leftRigthDifference(vector<int>& nums) {
    vector<int> res;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        vector<int> ls(nums.begin(), nums.begin()+i);
        vector<int> rs(nums.begin()+(i+1), nums.end());
        int left_sum = sum(ls);
        int right_sum = sum(rs);
        res.push_back(abs(left_sum - right_sum));
    }
    return res;
}

void solvep1(){
    string s;
    getline(cin, s);

    vector<string> arr_s = split_string(s);
    vector<int> nums;
    for(auto str: arr_s){
        nums.push_back(stoi(str));
    }

    vector<int> res = leftRigthDifference(nums);
    print_1d_vector(res);
}

vector<int> divisibilityArray(string word, int m) {
    vector<int> res;
    int n = word.size();
    int prev_rem = 0;
    for(int i = 0; i < n; i++){
        int rem = prev_rem*10 + (int(word[i]) - 48);
        res.push_back((rem % m == 0) ? 1 : 0);
        prev_rem = rem % m;
    }
    return res;
}

void solvep2(){
    string word;
    int m;
    getline(cin, word);
    cin >> m;
    vector<int> res = divisibilityArray(word, m);
    print_1d_vector(res);
}

int maxNumOfMarkedIndices(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n =  nums.size();
    int mid = n/2;
    int res = 0;
    int j = mid;
    for(int i = 0; i < mid; i++){
        while(j < n && 2*nums[i] > nums[j]){
            j++;
        }
        if(2*nums[i] <= nums[j]){
            res++;
            j++;
        }
        if(j >= n){ break; }
    }
    return res*2;
}

void solvep3(){
    string s;
    getline(cin, s);
    vector<string> arr_s = split_string(s);
    vector<int> nums;
    for(auto str: arr_s){
        nums.push_back(stoi(str));
    }

    int res = maxNumOfMarkedIndices(nums);
    cout << res << endl;
}